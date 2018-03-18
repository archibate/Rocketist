#pragma once

template <class T>
class VirInput {
private:
	T t;
public:
	VirInput() {}
	VirInput(const T &t) {
		set(t);
	}
	VirInput &operator=(const T &t) {
		set(t);
		return *this;
	}
	operator T() const {
		return get();
	}
//protected:
	virtual void set(const T &_t) {
		t = _t;
	}
	virtual T get() const {
		return t;
	}
};

typedef VirInput<real_t> VirInputf;
typedef VirInput<bool> VirInputb;
typedef VirInput<int> VirInputi;
