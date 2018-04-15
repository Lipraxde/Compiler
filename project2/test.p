/**
 * test.p: simple P language example
 */
//&T-
test;

var a: integer;		// global variable

foo( a, b: integer ): integer;
begin
	return a*b;
end
end foo

bar(a,b:integer;a:string);
begin

end
end bar

// main block
begin

	print foo();

end
end test
