template<typename T1, typename T2>
struct pair{
public:
    T1 first;
    T2 second;

    pair();
    pair(const T1& x, const T2& y);
private:
};

