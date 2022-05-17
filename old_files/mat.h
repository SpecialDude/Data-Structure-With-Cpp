namespace NDarray
{
    class ndarray
    {
        public:
            ndarray();
            ndarray(int dimensionsBound[], int ds);
            ndarray(int* thearray, int dimensions[], int ds);
            ndarray(const ndarray& narray);
            ~ndarray();
            void operator==(const ndarray& narray);
        private:
            int size;
            int dimension;
            int* narray;
            int* dimensionSize;
    };
}