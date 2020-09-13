template<typename type>
bool isSubArray(vector<type> sourceArray, vector<type> otherArray) {
    bool state{0};

    if(otherArray.empty()) {
        return 1;
    }
    else if(otherArray == sourceArray) {
        return 1;
    }
    else if(otherArray.size() > sourceArray.size()) {
        return 0;
    }
    else {
        forK(0, sourceArray.size()) {
            if(sourceArray.at(k) == otherArray.at(0)) {
                int n = 1;
                while ( (n < otherArray.size() ) && (sourceArray.at(k + n) == otherArray.at(n)) ) {
                    n++;
                }

                if( n == otherArray.size() ){
                    state = 1;
                }
            }
        }
    }

    return state;
}
