class Incognizable {
public:
	Incognizable() {_a = 0; _b = 0;}
	Incognizable(const int& a) {_a = a; _b = 0;}
	Incognizable(const int& a, const int& b) {_a = a; _b = b;}
private:
	int _a, _b;
};
