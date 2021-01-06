template <class T>
forward_iterator<T> Element<T>::next(){
    return forward_iterator<T>(next_el.get());
}

