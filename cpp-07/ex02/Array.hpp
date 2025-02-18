
template <typename T>
class Array
{
		private:
			T	*data;
			unsigned int	size;
		public:
			Array();
			Array(unsigned int n);
			Array(const Array &model);
			~Array();
			T	operator[ ](unsigned int n):
};

