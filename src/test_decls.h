/*
 * test_decls.h
 *
 */

#ifndef TEST_DECLS_H_
#define TEST_DECLS_H_


void globalVoidFunction(std::string msg, int num) {
	printf("called globalFunction(msg = '%s', num = %d)\n", msg.c_str(), num);
}

int globalIntFunction(int numA, int numB) {
  return numA * numB;
}

std::string&  globalStringFunction(int numA, int numB) {

}

#endif /* TEST_DECLS_H_ */
