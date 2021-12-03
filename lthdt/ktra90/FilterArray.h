// #ifndef FILTERARRAY_H
// #define FILTERARRAY_H
#include "NumberArray.h"
using namespace std;
class FilterArray
{
    public:
        virtual double transform (double)=0;
        NumberArray doFilter (NumberArray& n){
            NumberArray r(n.getSize());
            for( int i=0; i< n.getSize(); i++){
                r.set(i, transform(n.get(i)));
            }
            return r;
        }
};
class FACopy: public FilterArray{
    public:
        double transform (double d){
            return d;
        }
};
class FAInteger: public FilterArray{
    public:
        double transform (double d){
            return (int)d;
        }
};
class FAAdd: public FilterArray{
    private:
        double value;
    public:
        FAAdd(){}
        FAAdd(double v){
            value=v;
        }
        double transform (double d){
            return d+value;
        }
};


//#endif /* FILTERARRAY_H */
