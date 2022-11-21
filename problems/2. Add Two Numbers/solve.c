#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode*	inputIterator;
	struct ListNode*	resultIterator;
	struct ListNode*	result;

	result = malloc(sizeof(struct ListNode));
	result->val = 0;

	addNodes(l1, result);
	addNodes(l2, result);

	return result;
}

void addNodes(struct ListNode* l, struct ListNode* result)
{
	struct ListNode*	inputIterator;
	struct ListNode*	resultIterator;

	inputIterator = l;
	resultIterator = result;
	resultIterator->val += inputIterator->val;
	checkDigit(resultIterator);

	while (inputIterator->next != NULL) {
		inputIterator = inputIterator->next;

		if (resultIterator->next == NULL) {
			resultIterator->next = malloc(sizeof(struct ListNode));
			resultIterator->next->val = 0;
		}
		resultIterator = resultIterator->next;
		resultIterator->val += inputIterator->val;
		checkDigit(resultIterator);
	}
}

void checkDigit(struct ListNode* l1)
{
	if (l1->val > 9) {
		if (l1->next == NULL) {
			l1->next = malloc(sizeof(struct ListNode));
			l1->val = 1;
		} else {
			l1->next->val += 1;
		}
	}
}

void printList(struct ListNode* p)
{
	while (p != NULL) {
		printf("->%d", p->val);
		p = p->next;
	}
	printf("\n");
}
