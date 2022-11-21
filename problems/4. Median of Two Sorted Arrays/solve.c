
double getMean(int current, int last, int rest)
{
	if (rest == 1) {
		return (double) current;
	}
	return (double) last + ((double) (current - last)) / 2;
}

double getAns(int rest, int* nums, int i, int last, int left)
{
	if (left == 1) {
		return getMean(nums[i], last, rest);
	}
	return getMean(nums[i + left - 1], nums[i + left - 2], rest);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int     i1;
	int     i2;
	int     left;
	int     rest;
	int     last;
	int     current;

	left = 1 + (nums1Size + nums2Size) / 2;
	rest = (nums1Size + nums2Size) % 2;

	i1 = 0;
	i2 = 0;
	for (; left > 0; left--) {
		if (i1 == nums1Size) {
			return getAns(rest, nums2, i2, current, left);
		} else if (i2 == nums2Size) {
			return getAns(rest, nums1, i1, current, left);
		}
		last = current;

		if (nums1[i1] < nums2[i2]) {
			current = nums1[i1];
			i1++;
		} else {
			current = nums2[i2];
			i2++;
		}
	}
	return getMean(current, last, rest);
}