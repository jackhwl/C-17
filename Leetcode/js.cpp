function add(first, second) {
	return first + second;
}
function sub(first, second) {
	return first - second;
}
function mul(first, second) {
	return first * second;
}

function identity(x) {
	return function() {
		return x;
	}
}

function addf(x) {
	return function(y) {
		return x + y;
	}
}

function liftf(f) {
	return function(x) {
		return function(y) {
			return f(x, y);
		};
	};
}

function curry(f, x) {
	return function(y) {
		return f(x, y);
	};
}

function curry2(f, x) {
	return liftf(f)(x);
}

function curry3(func, ...first) {
	return function(...second) {
		return func(...first, ...second);
	};
}

/*
var add1 = liftf(add);
console.log(add1(3)(7));
console.log(liftf(mul)(3)(4));
var add3 = curry(add,3);
console.log(add3(4));
console.log(curry(mul, 5)(6));

var inc0 = addf(1);
var inc1 = curry(add,1);
var inc = liftf(add)(1);

console.log(inc(5));
*/

function twice(func) {
	return function(x) {
		return func(x, x);
	}
}

//console.log(twice(mul)(5));

function reverse(func) {
	return function(x, y) {
		return func(y, x);
	};
}

//console.log(reverse(sub)(3,2));

function composeu(func1, func2) {
	return function(x) {
		return func2(func1(x));
	};
}
/*
var doubl = twice(add);
var square = twice(mul);
console.log(composeu(doubl, square)(5))
*/
function composeb(f, g) {
	return function(x, y, z) {
		return g(f(x, y), z);
	};
}

function limit(f, n) {
	var counter = 0;
	return function(x, y) {
		if (counter < n) {
			counter++;
			return f(x, y);
		}
		//return undefined;
	};
}
/*
var add_ltd = limit(add, 1);
console.log(add_ltd(3,4));
console.log(add_ltd(3,4));
*/

function from(n) {
	return function() {
		return n++;
	};
}
/*
var index = from(0);
console.log(index());
console.log(index());
console.log(index());
console.log(index());
*/

function to(f, m) {
	return function() {
		var n = f();
		if (n < m) {
			return n;
		}
	};
}

/*
var index = to(from(1), 3);
console.log(index());
console.log(index());
console.log(index());
*/

function fromTo1(n, m) {
	return function() {
		if (n<m) {
			return n++;
		}
	};
}

function fromTo(n, m) {
	return to(from(n), m);
}
/*
var index = fromTo(0,3);
console.log(index());
console.log(index());
console.log(index());
console.log(index());
console.log(index());
*/

function element(arr, gen) {
	if (gen == = undefined) {
		gen = fromTo(0, arr.length);
	}
	return function() {
		var n = gen();
		if (n != = undefined) {
			return arr[n];
		}

	};
}

var ele = element(['a', 'b', 'c', 'd']);
console.log(ele());
console.log(ele());
console.log(ele());
console.log(ele());
console.log(ele());

//function challenge 1-4