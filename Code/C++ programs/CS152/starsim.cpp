#include<simplecpp>

class V3
{
private :
    double x, y, z;
public :
    V3(){};
    V3(double p, double q, double r)
    {
        x=p; y=q; z=r;
    };
    V3 operator+(V3 const &w) const
    {
        return V3(x+w.x, y+w.y, z+w.z);
    };
     V3 operator-(V3 const &w) const
    {
        return V3(x-w.x, y-w.y, z-w.z);
    };
    V3 operator*(double t) const
    {
        return V3(x*t, y*t, z*t);
    };
    double length() const
    {
        return sqrt(x*x+y*y+z*z);
    };
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
};

class Star
{
private :
    Circle image;
    double mass;
    V3 r, v;
public :
    Star() {};
    void init(double m, V3 position, V3 velocity)
    {
        mass=m;
        r=position;
        v=velocity;
        image.reset(r.getX(),r.getY(),15);
        image.setColor(COLOR("red"));
        image.setFill(true);
        image.penDown();
    }
    void vStep(double dT, V3 f)
    {
        v=v+f*(dT/mass);
    }
    void rStep(double dT)
    {
        V3 d=v*dT;
        image.move(d.getX(),d.getY());
        r=r+d;
    }
    V3 forceOf(Star &s)
    {
        V3 R=s.r-r;
        return R*(mass*s.mass/pow(R.length(),3));
    }
};

void read_star_data(Star stars[], int n)
{
    double mass, vx, vy, vz, x, y, z;
    for(int i=0; i<n; i++)
    {
        cin >> mass >> x >> y >> z >> vx >> vy >> vz;
        stars[i].init(mass, V3(x, y, z), V3(vx, vy, vz));
    }
}

void calculate_net_force(int n, Star stars[], V3 forces[])
{
    for(int i=0; i<n; i++) forces[i]=V3(0,0,0);

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            V3 f=stars[i].forceOf(stars[j]);
            forces[i]=forces[i]+f;
            forces[j]=forces[j]-f;
        }
    }
}

main_program
{
    initCanvas("N body problem", 800, 800);

    double T, delta;
    cin >> T >> delta;
    int n;
    cin >> n;
    Star stars[n];
    read_star_data(stars, n);
    V3 forces[n];
    calculate_net_force(n, stars, forces);
    for(int i=0; i<n; i++) stars[i].vStep(delta/2, forces[i]);

    for(float t=0; t<T; t+=delta)
    {
        for(int i=0; i<n; i++) stars[i].rStep(delta);
        calculate_net_force(n, stars, forces);
        for(int i=0; i<n; i++) stars[i].vStep(delta, forces[i]);
    }

    getClick();
}
