#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* initListNode(int val, struct ListNode* next)
{
	struct ListNode*	p;

	p = malloc(sizeof(struct ListNode));
	p->val = val;
	p->next = next;

	return p;
}

void checkDigits(struct ListNode* l)
{
	if (l->val > 9) {
		l->val -= 10;
		if (l->next == NULL) {
			l->next = initListNode(1, NULL);
		} else {
			l->next->val += 1;
		}
	}

	if (l->next != NULL) {
		checkDigits(l->next);
	}
}

void addNodes(struct ListNode* l, struct ListNode* result)
{
	struct ListNode*	inputIterator;
	struct ListNode*	resultIterator;

	inputIterator = l;
	resultIterator = result;
	resultIterator->val += inputIterator->val;

	while (inputIterator->next != NULL) {
		inputIterator = inputIterator->next;

		if (resultIterator->next == NULL) {
			resultIterator->next = initListNode(0, NULL);
		}
		resultIterator = resultIterator->next;
		resultIterator->val += inputIterator->val;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode*	inputIterator;
	struct ListNode*	resultIterator;
	struct ListNode*	result;

	result = malloc(sizeof(struct ListNode));
	result->val = 0;
	result->next = NULL;

	addNodes(l1, result);
	addNodes(l2, result);
	checkDigits(result);

	return result;
}
