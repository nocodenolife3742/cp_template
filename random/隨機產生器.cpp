// default code version : 1.4

mt19937_64 rnd(clk());
ll my_rand(ll m)
{
    return (ull)rnd() % m;
}