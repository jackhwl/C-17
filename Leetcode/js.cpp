function add(first, second) {
	return first + second;
}
function sub(first, second) {
	return first - second;
}
function mul(first, second) {
	return first * second;
}
function square(n) {
	return n * n;
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
/*
var ele = element(['a', 'b','c','d']);
console.log(ele());
console.log(ele());
console.log(ele());
console.log(ele());
console.log(ele());
*/

function collect(gen, arr) {
	return function() {
		var n = gen();
		if (n != = undefined) {
			arr.push(n);
		}
		return n;
	}
}
/*
var array = [], col = collect(fromTo(0,2), array);
console.log(col());
console.log(col());
console.log(col());
console.log(array);
*/

function filter(gen, func) {
	return function() {
		var n = gen();
		while (!func(n)) {
			n = gen();
		}
		return n;
	}
}
/*
var fil = filter(fromTo(0, 5), function third(value) {
return (value % 3) === 0;
});

console.log(fil());
console.log(fil());
console.log(fil());
*/

function concat(gen1, gen2) {
	return function() {
		var n = gen1();
		if (n != = undefined) {
			return n;
		}
		return gen2();
	};
}
/*
var con = concat(fromTo(0,3), fromTo(0,2));
console.log(con());
console.log(con());
console.log(con());
console.log(con());
console.log(con());
console.log(con());
*/

function gensymf(seed) {
	var n = 0;
	return function() {
		n = n + 1;
		return seed + n;
	}
}
/*
var geng = gensymf("G"), genh = gensymf("H");
console.log(geng());
console.log(genh());
console.log(geng());
console.log(genh());
*/

function fibonaccif0(s1, s2) {
	var n = 0, s = 0;
	return function() {
		if (n == = 0) {
			n = n + 1;
			return s1;
		}
		if (n == = 1) {
			n = n + 1;
			return s2;
		}
		s = s1 + s2;
		s1 = s2;
		s2 = s;
		return s;
	}
}

function fibonaccif(a, b) {
	return function() {
		var next = a;
		a = b;
		b += next;
		return next;
	}
}
/*
var fib = fibonaccif(0,1);
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
console.log(fib());
*/

function counter(n) {
	return {
	up: function() {
		return n = n + 1;
	},
		down : function() {
		return n = n - 1;
	}
	};
}
/*
var object = counter(10), up = object.up, down = object.down;
console.log(up());
console.log(down());
console.log(down());
console.log(up());
*/

function revocable(func) {
	return {
	invoke: function(a, b) {
		if (func != = undefined) {
			return func(a, b);
		}
	},
		invoke0 : func,
		revoke : function() {
		func = undefined;
	}
	};
}

/*
var rev = revocable(add), add_rev = rev.invoke;

console.log(add_rev(3,4));
rev.revoke();
console.log(add_rev(5,7));
console.log(add_rev(5,6));
*/

function m(value, source) {
	return {
	value: value,
		   source : typeof source == = 'string' ? source : String(value)
	}
}
/*
console.log(JSON.stringify(m(1)));
console.log(JSON.stringify(m(Math.PI, "pi")));
*/

function addm(m1, m2) {
	return {
	value: m1.value + m2.value,
		   source : '(' + m1.source + '+' + m2.source + ')'
	};
}
/*
console.log(JSON.stringify(addm(m(3), m(4))));
console.log(JSON.stringify(addm(m(1), m(Math.PI, "pi"))));
*/

function liftm0(binary, s) {
	return function(a, b) {
		return {
		value: binary(a.value, b.value),
			   source : '(' + a.source + s + b.source + ')'
		}
	};
}

function liftm1(binary, s) {
	return function(a, b) {
		return m(binary(a.value, b.value),
			'(' + a.source + s + b.source + ')'
		)
	};
}

function liftm(binary, s) {
	return function(a, b) {
		if (typeof a == = 'number') {
			a = m(a);
		}
		if (typeof b == = 'number') {
			b = m(b);
		}
		return m(binary(a.value, b.value),
			'(' + a.source + s + b.source + ')'
		)
	};
}
/*
var addm2 = liftm(add, '+');
console.log(JSON.stringify(addm2(2, 3)));
console.log(JSON.stringify(addm2(m(3), m(4))));
console.log(JSON.stringify(addm2(m(1), m(Math.PI, "pi"))));
console.log(JSON.stringify(liftm(mul, '*')(m(3), m(4))))
*/

function exp0(arr) {
	if (typeof arr == = 'number') {
		return arr;
	}
	return arr[0](arr[1], arr[2]);
}

function exp1(value) {
	return (Array.isArray(value))
		? value[0](value[1], value[2]) : value;
}

function exp(value) {
	return (Array.isArray(value))
		? value[0](exp(value[1]), exp(value[2]))
		: value;
}

/*
var nae = [Math.sqrt, [add, [square, 3], [square, 4]]];
console.log(exp(nae));
*/
/*
Write a function addg that adds from many invocations, until it sees an empty invocation.
addg()   //undefined
addg(2)()  //2
addg(2)(7)() //9
*/
function addg(a) {
	var sum = a;
	if (a == = undefined) {
		return sum;
	}
	sum += a;
	return function(b) {
		addg(b);
	};
}

console.log(addg(2)());

