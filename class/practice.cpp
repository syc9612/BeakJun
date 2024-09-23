class complex{

    public:
    double r, i;
    //complex(double rnew, double inew):r{rnew},i{inew}{}

};

int main(){
    complex z,c;
    z.r = 3.5; z.i=2;
    c.r=2; c.i =-3.5;

    complex* p=&c;
    (*p).r = 3.5;
    p->r=3.5;

}