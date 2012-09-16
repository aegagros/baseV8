
function MyObjectA(attributeA, attributeB) {
  this.attributeA = attributeA;
  this.attributeB = attributeB;
}

function MyObjectB() {
  this.doIt = function() {
      print('called doIt()');
  };
}

function dummy() {
	var objB = new MyObjectB();
	objB.doIt();

	var objC = new MyType('manolis', 10);
	print(objC);
	print(objC.prop);
	print('before calling gMethod: ' + objC.publicProp);
	objC.gMethod("215", 45);
	print("after calling gMethod: " + objC.publicProp);
	print(objC.global_int);
	print(objC.str);
	objC.aMethod("test1");
	objC.global_int = 15;
	
	var objs = new Array();

	for (var i = 0; i < 10; i++) {
		objs[i] = new MyType('value: ' + i, i)		
		objs[i].publicProp = i % 4;
		print(i + ': prop: ' + objs[i].prop + ' publicProp: ' + objs[i].publicProp + 
			  ' str: "' + objC.str + '"');
		objs[i].printMessage(i + " works like a charm!");
	}
	
	var objA = new MyObjectA (10, 'manolis');
	var msg = objA.attributeA + ": " + objA.attributeB;
	//print(msg);
	print("Hello people! This is Javascript!");
}

dummy();
