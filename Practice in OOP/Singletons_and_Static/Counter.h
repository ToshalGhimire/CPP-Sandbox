#ifndef SimpleCounter_H
#define SimpleCounter_H



class SimpleCounter
{
    public:
        SimpleCounter();

        int get_i() { return i; }
        void inc(){i++;}

    private:
        static int i;
};

class SingleCounter {
    public:
        static SingleCounter& GetInstance()
        {
            static SingleCounter instance;
            return instance;
        }

    void IncrementCounter() {this->count_++;}

    int getCount(){return count_;}

    private:
        int count_;

};
#endif // SimpleCounter_H
