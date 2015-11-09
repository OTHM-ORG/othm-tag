#include <stdio.h>
#include <othm_tag.h>

struct rtag {
	char *str;
};

struct ltag {
	char *str;
};

struct test_struct {
	char *str;
};

int main(void)
{
	OTHM_LEFT_TAGGED_INIT(struct ltag, struct test_struct,
			      left_test_whole, left_test_tagged);
	OTHM_GET_LEFT_TAG(struct ltag *, left_test_tagged)->str = "Hello ";
	left_test_tagged->str = "World ";

	OTHM_RIGHT_TAGGED_INIT(struct rtag, struct test_struct,
			       right_test_whole, right_test_tagged);
	OTHM_GET_RIGHT_TAG(struct rtag *, right_test_tagged)->str = "this ";
	right_test_tagged->str = "is ";

	OTHM_BOTH_TAGGED_INIT(struct rtag, struct ltag, struct test_struct,
			      both_test_whole, both_test_tagged);
	OTHM_GET_LEFT_TAG(struct ltag *, both_test_tagged)->str = "a ";
	OTHM_GET_RIGHT_TAG(struct rtag *, both_test_tagged)->str = "test";
	both_test_tagged->str = "!\n";

	printf("%s%s%s%s%s%s%s",
	       OTHM_GET_LEFT_TAG(struct ltag *, left_test_tagged)->str,
	       OTHM_GET_TAGGED_LEFT
	       (struct test_struct *,
		(struct ltag *)&left_test_whole)->str,
	       OTHM_GET_RIGHT_TAG(struct rtag *, right_test_tagged)->str,
	       OTHM_GET_TAGGED_RIGHT
	       (struct test_struct *,
		OTHM_GET_RIGHT_TAG(struct rtag *,
				   right_test_tagged))->str,
	       OTHM_GET_LEFT_TAG(struct ltag *, both_test_tagged)->str,
	       OTHM_GET_RIGHT_TAG_FROM_LEFT
	       (struct rtag *, struct test_struct *,
		OTHM_GET_LEFT_TAG(struct ltag *, both_test_tagged))->str,
		both_test_tagged->str);

	return 0;
}
