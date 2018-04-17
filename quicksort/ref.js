const quickSort = (arr) => {
  if (arr.length < 2) return arr;

  let pivotIndex = 0;
  let storeIndex = pivotIndex + 1;

  let lo = [];
  let hi = [];

  for (let i = 1; i < arr.length; i++) {
    if(arr[i] < arr[pivotIndex]) {
      lo.push(arr[i]);
    }
    if(arr[i] >= arr[pivotIndex]) {
      hi.push(arr[i]);
    }
  }

  let sortedHead = quickSort(lo);
  let sortedTail = quickSort(hi);

  return sortedHead.concat(arr[pivotIndex], sortedTail)
}