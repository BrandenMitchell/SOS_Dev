// // merge sort is another divide and conquor strat that splits arr into half and puts each half in a sub array, it recursively cuts the arr in half and concatenates all of it together

// // two function algo,
// //merge sort, this function takes in an arr and checks that the array has elements in it,
// //      next it gets the middle of the array using Math floor function and then  creates a left sub arr and a right sub arr, uses the slice method to get the ranges.

// //recursively calls mergesort function on the two arrs
// //returns a call to Merge function that passes the two arrs


// //merge funciton takes in a left and right arr and merges them together
// //creates a sortedArray that will hold the sorted arr when done, then 2 pointers are created initialized at a value of 0, they will be used to traverse the arrays
// // using a while loop we will loop through both arrs until both the left and right index ptrs are == arr.length
// // if the left[leftptr] < righ[rightptr]
//     //we willpush right value onto sorted and increment left
//     //else we push left value onto arr and increment right ptr


// //return the sorted arr


const mergeSort = (arr) =>{

    //base case if arr.len <=1
    if (arr.length <= 1){
        return arr;
        //arr is sorted
    }

    //find midpoint of the arr
    const mid = Math.floor(arr.length / 2);

    //inizialize two sub arrs using the midpt
    const left = mergeSort(arr.slice(0,mid)); //goes from 0 to the midpt
    const right = mergeSort(arr.slice(mid)); ///goes from mid to end of arr
     //recursively call on both arrs
    //calll the merge function

    return Merge(left,right);
}

const Merge = (left,right) =>{

    

    //arr to store sorted arr
    const sorted_arr= [];

    let leftptr = 0;
    let rightptr = 0;
    //call while loop to move through the sorted arr and compare the values at the left and right pointers and add them to their respective arr

    while(leftptr < left.length && rightptr < right.length){

        if (left[leftptr] < right[rightptr]){
            sorted_arr.push(left[leftptr]);
            leftptr++;

        }   
        else{
            sorted_arr.push(right[rightptr]);
            rightptr++;

        }

    }
    
    //now check both arr's remaining items

    while(leftptr < left.length){
        sorted_arr.push(left[leftptr]);
        leftptr++;
    }
    while(rightptr < right.length){
        sorted_arr.push(right[rightptr]);
        rightptr++;
    }

    return sorted_arr;



}




const arr = [38, 27, 43, 3, 9, 82, 10];
const sortedArr = mergeSort(arr);
console.log(sortedArr); // Output: [3, 9, 10, 27, 38, 43, 82]



