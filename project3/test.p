//&T-
//&P-
test;

// no global declaration(s)

func( a:integer ; b, e:array 1 to 2 of array 2 to 4 of boolean ): boolean;
begin
	var c: "hello world!";
	var d: "hello world!";
	begin
		var d: real;
		return (b[1][4] >= 1.0);
	end
end
end func

bar();
begin

end
end bar

begin
	var a: integer;
	begin
		var a, c: boolean; // outer ’a’ has been hidden in this scope
	end
	a := a+b*c;
	a := b*c;
	func(a+c, b);
end
end test

