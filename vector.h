//https://www.tutorialspoint.com/cpp_standard_library/vector.htm
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>


template <class T> class Vector { // The slower and less stable implementation of std::vector! Incompatable with  the C++11 for cycles that use const Vector. Amazing!
public: // interfeisas
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    size_type size() const { return avail - _data; }
    size_type capacity() const { return limit - _data; }
    size_type max_size() { return (pow(2, 31)/sizeof(T) - 1); } // Kadangi negalima lengvai pasiziureti ant kokios masinos veikia, dydis skaiciuojamas pagal 32 bitu sistema
    iterator begin() { return _data; }
    const_iterator cbegin() const { return _data; }
    iterator end() { return avail; }
    const_iterator cend() const { return avail; }
    value_type* data() { return _data; } //  -  returns a pointer to the first element of the vector container.
    const value_type* data() const { return _data; }
    value_type& back() { return *(avail-1); }
    value_type& front() { return *_data; }

    class reverse_iterator {
        iterator r_it;
    public:
        iterator base() { return r_it; }
        reverse_iterator(iterator it = nullptr) {r_it = it;}
        reverse_iterator operator+(size_type val) { return r_it-val; }
        reverse_iterator& operator++() { r_it = r_it - 1; return r_it; } //prefix
        reverse_iterator operator++(int) {
            reverse_iterator result = r_it; // makes a copy
            --(r_it); // changes the value
            return result; // returns the old value
        } //postfix
        reverse_iterator operator-(size_type val) { return r_it+val; }
        reverse_iterator operator--() { r_it = r_it + 1; return r_it; }
        reverse_iterator operator--(int) {
            reverse_iterator result = r_it; // makes a copy
            ++(r_it); // changes the value
            return result; // returns the old value
        } //postfix
        reverse_iterator operator+=(size_type val) { r_it = r_it-val; return r_it; }
        reverse_iterator operator-=(size_type val) { r_it = r_it+val; return r_it; }
        value_type operator*() { return *(r_it); }
        //Comparisons:
        bool operator< (reverse_iterator it) {return r_it> it;}
        bool operator<=(reverse_iterator it) {return r_it>=it;}
        bool operator> (reverse_iterator it) {return r_it< it;}
        bool operator>=(reverse_iterator it) {return r_it<=it;}
        bool operator==(reverse_iterator it) {return r_it==it;}
        bool operator!=(reverse_iterator it) {return r_it!=it;}
    };

    Vector() { create(); } //Default constructor
    explicit Vector(size_type n, const T& t = T{}) { create(n, t); }//Fill / range constructor
    Vector(const Vector& v) { create(v.cbegin(), v.cend()); } //Copy constructor
    template <class InputIterator> Vector(InputIterator begin, InputIterator end) { create(begin, end); } // Range copy constructor
    Vector(Vector&& v) { create(v.begin(), v.end()); v.uncreate(); } //Move constructor
    Vector(std::initializer_list<T> l) { create(l); }

    ~Vector() { uncreate(); }

    T& operator[](size_type i) { return _data[i]; }
    const T& operator[](size_type i) const { return _data[i]; }

    Vector<T>& operator=(const Vector& v) {
        // patikriname ar ne lygu
        if (&v != this) {
            uncreate();
            create(v.cbegin(), v.cend());
        }
        return *this;
    }
    Vector<T>& operator=(Vector&& v) {
        // patikriname ar ne lygu
        if (&v != this) {
            uncreate();
            create(v.cbegin(), v.cend());
            v.uncreate();
        }
        return *this;
    }
    bool operator!=(const Vector& v) {
        if(size()!=v.size()) return true;
        iterator it=begin();
        const_iterator itv=v.cbegin();
        for(size_type i=0; i<size(); i++) if(*(it+i)!=*(itv+i)) return true;
        return false;
    }
    bool operator<(const Vector& v) {
        size_type n = size()>v.size() ? v.size() : size();
        iterator it=begin();
        const_iterator itv=v.cbegin();
        for(size_type i=0; i<n; i++) if(*(it+i)>=*(itv+i)) return false;
        return true;
    }
    bool operator<=(const Vector& v) {
        size_type n = size()>v.size() ? v.size() : size();
        iterator it=begin();
        const_iterator itv=v.cbegin();
        for(size_type i=0; i<n; i++) if(*(it+i)>*(itv+i)) return false;
        return true;
    }
    bool operator>(const Vector& v) {
        size_type n = size()>v.size() ? v.size() : size();
        iterator it=begin();
        const_iterator itv=v.cbegin();
        for(size_type i=0; i<n; i++) if(*(it+i)<=*(itv+i)) return false;
        return true;
    }

    bool operator>=(const Vector& v) {
        size_type n = size()>v.size() ? v.size() : size();
        iterator it=begin();
        const_iterator itv=v.cbegin();
        for(size_type i=0; i<n; i++) if(*(it+i)<*(itv+i)) return false;
        return true;
    }

    void assign(size_type n, const value_type& val) {
        if(size()==n) for(iterator i = begin(); i<end(); i++) *i = val;
        else {
            uncreate();
            create(n, val);
        }
    } //- fill ver.
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last) {
        if(size()==std::distance(first, last)) for(size_type i = 0; i<size(); i++) *(_data+i) = *(first+i);
        else {
            uncreate();
            create(first, last);
        }
    } //- range ver.
    void assign(std::initializer_list<T> l) {
        uncreate();
        create(l);
    } // - initialiser list ver.

    value_type at(size_type i) {
        if(i<size()) return(_data[i]);
        else throw std::out_of_range("wrong integer at Vector.at()");
    }
    void push_back(const T& t) { if(avail==limit) grow_up(); unchecked_append(t); }
    void push_back(T&& t) { emplace_back(std::move(t)); }
    void pop_back() {
        avail--;
        alloc.destroy(avail);
    } // removes last element from vector and reduces size of vector by one.

    void clear() {
        iterator it = avail;
        while (it != _data) alloc.destroy(--it);
        avail = _data;
    } // - clears the vector by removing all elements from the vector and sets size of vector to zero.
    void reserve(size_type n) {
        if(capacity()<n) {
            iterator new_data = alloc.allocate(n);
            for(size_type i = 0; i<size(); i++) *(new_data+i)=*(_data+i);
            size_type sz = size();
            uncreate();
            avail = n>=sz ? new_data + sz : new_data + n;
            _data = new_data;
            limit = _data+n;
        }
    } //- Requests to reserve vector capacity be at least enough to contain n elements.

    void resize(size_type n, value_type val = T()) {
        if(n<size()) {
            for(iterator it = avail; it>begin()+n; it--) alloc.destroy(it);
            avail = begin()+n;
        }
        else {
            reserve(n);
            for(iterator it = avail; it>limit; it++) *it = 0;
            avail = limit;
        }
    } // Pakeicia vektoriaus dydi; ciklas ir distance() gadina laika

    void shrink_to_fit() {
        iterator new_data = alloc.allocate(size());
        for(size_type i = 0; i<size(); i++) *(new_data+i)=*(_data+i);
        size_type sz = size();
        uncreate();
        avail = new_data + sz;
        _data = new_data;
        limit = _data+sz;
    } //- Requests the container to reduce it's capacity to fit its size.

    void swap(Vector<T>& x) {
        Vector<T> temp(x);
        x = *this;
        *this = temp;
    } // Exchanges the content of vector with contents of vector x.

    template<class... Args> iterator emplace(iterator pos, Args&&... args) {
        if(avail==limit) {
            size_type dist = std::distance(begin(), pos);
            grow_up();
            pos = begin()+dist;
        }
        avail++;
        for(iterator it = avail; it>pos; it--) *it = *(it-1);
        alloc.construct(pos, std::forward<Args>(args)...);
        return pos;
    }
    template<class... Args> void emplace_back(Args&&... args) {
        if(avail==limit) grow_up();
        alloc.construct(avail, std::forward<Args>(args)...);
        avail++;
    }
    bool empty() { if(size()==0) return(true); else return(false); }

    iterator erase(iterator pos){
        size_type n = std::distance(_data, pos); // negalima is naujo naudoti iteratoriaus ji tiesiog nusiunciant atgal
        for(iterator it=pos; it<avail; it++) *it = *(it+1);
        avail--;
        alloc.destroy(avail);
        return _data+n;
    } //erases one element

    iterator erase(iterator first, iterator last) {
        size_type n = std::distance(first, last);
        size_type m = std::distance(_data, first);
        for(iterator it = last; it<end(); it++) *(it-n) = *it;
        for(iterator it = end(); it>end()-n; it--) alloc.destroy(it);
        avail -= n;
        return _data+m;
    } // erases a range or elements

    std::allocator<T> get_allocator() { return alloc; } //returns an allocator associated with vector.

    iterator insert(iterator pos, const value_type& val) {emplace(pos, val); return pos;}
    iterator insert(iterator pos, value_type&& val) {emplace(pos, val); return pos;}
    void insert(iterator pos, size_type n, value_type val) {
        if(size()+n>capacity()) {
            // Kadangi pakeiciant masyvo vieta su iteratorius igija nesamoninga reiksme,
            // apskaiciuoju atstuma tarp begin() ir pos ir po grow priskiriu pos nauja pozicija.
            size_type m = std::distance(begin(), pos);
            while(size()+n>capacity()) grow_up();
            pos = begin()+m;
        }
        avail+=n;
        //Perkelia viska per n poziciju
        for(iterator it=avail; it>=pos; it--) *(it+n) = *it;
        for(iterator it=pos; it<pos+n; it++) *it = val;
    } //fill version
    template <class InputIterator> void insert(iterator pos, InputIterator first, InputIterator last) {
        size_type n = std::distance(first, last);
        if(size()+n>capacity()) {
            // Kadangi pakeiciant masyvo vieta su iteratorius igija nesamoninga reiksme,
            // apskaiciuoju atstuma tarp begin() ir pos ir po grow priskiriu pos nauja pozicija.
            size_type m = std::distance(begin(), pos);
            while(size()+n>capacity()) grow_up();
            pos = begin()+m;
        }
        avail+=n;
        //Perkelia viska per n poziciju
        for(iterator it=avail; it>=pos; it--) *(it+n) = *it;
        for(size_type i = 0; i<n; i++) *(pos+i) = *(first+i);
    } //range version

    reverse_iterator rbegin() { return _data; }
    reverse_iterator rend() { return avail; }
    const reverse_iterator crbegin() const { return _data; }
    const reverse_iterator crend() const { return avail; }

private:
    iterator _data;
    iterator avail; // pirmasis po paskutiniojo sukonstruoto Vector elementas
    iterator limit;

    std::allocator<T> alloc;
    void create() { _data = avail = limit = nullptr; }
    void create(size_type n, const T& val) {
        _data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
        limit = avail = _data + n;
        std::uninitialized_fill(_data, limit, val); // inicializuoja elementus val reikšme
    }
    void create(const_iterator i, const_iterator j) {
        _data = alloc.allocate(j - i); // išskirti vietos j-i elementams
        limit = avail = std::uninitialized_copy(i, j, _data); // nukopijuoja elementus iš intervalo
    }
    void create(std::initializer_list<T> l) {
        _data = alloc.allocate(l.size());
        limit = avail = std::uninitialized_copy(l.begin(), l.end(), _data);
    }
    // sunaikinti elementus array ir atlaisvinti atmintį
    void uncreate() {
        if (_data) {
            // sunaikinti (atbuline tvarka) sukonstruotus elementus
            iterator it = avail;
            while (it != _data) alloc.destroy(--it);
            // atlaisvinti išskirtą atmintį. Turi būti _data != nullptr
            alloc.deallocate(_data, limit - _data);
        }
        // reset'inam pointer'iuss - Vector'ius tuščias
        _data = limit = avail = nullptr;
    }
    // pagalbinės funkcijos push_back realizacijai
    void grow_up() {
        // dvigubai daugiau vietos, nei buvo
        size_type new_size = std::max(2 * (limit - _data), ptrdiff_t(1));
        // išskirti naują vietą ir perkopijuoti egzistuojančius elementus
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(_data, avail, new_data);
        // atlaisvinti seną vietą
        uncreate();
        // reset'int rodykles į naujai išskirtą vietą
        _data = new_data;
        avail = new_avail;
        limit = _data + new_size;
    }
    // tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
    void unchecked_append(const T& val) { alloc.construct(avail++, val); }
};

template<class T> class allocator {
  public:
    T* allocate(size_t); // išskirti `raw` atmintį
    void deallocate(T*, size_t); // atlaisvinti atmintį
    void construct(T*, const T&); // sukonstruoti 1 objektą
    void destroy(T*); // sunaikinti 1 objektą
};
