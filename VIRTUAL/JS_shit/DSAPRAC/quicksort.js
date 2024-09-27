

// javascript quick sort implementation and understanding


//base cases first the functiion checks if the array has any or one element if so it returns array bc its sorted 

//pivot is chosen 
// two arrays are created and eventually called recursively on both arrays

//this has average of nlongn but a worst of n^2!!  its  when you get a bad pivot number and the arrays are very lopsided pickin a random value can help

// once the arrays and pivot are created we loop through given and compare each value at i in the array to our pivot
//we place the arrayvalue at i into either the left array if its smaller or the right arrray if its bigger

//at the end we return a callback to the function (recursively) on the left and right arrays created, we also return the pivot . 
// we use the spread operator on the function calls as it allows accessing of every item in the array

// const quicksort = (array) => {


    
//     //base case
//     if (array.length <= 1){
//         return array;

//     }

//     //pivot
//     const pivot = array[0];

//     const left = [];
//     const right = [];
    
//     for (let i = 1; i < array.length ; i++) {
//         if (array[i] < pivot) {
//             left.push(array[i]);
//         } else {
//             right.push(array[i]);
//         }
//     }
//     console.log(left, right);

//     // this line of code returns an array containing the result of running the function on the two arrays we created this return includes the pivot so we dont lose it 
//     return[...quicksort(left),pivot,...quicksort(right)];


// }


// const Arr = [3, 6, 8, 10, 1, 2, 1];
// const sorted = quicksort(Arr);
// console.log(`sorted array: ${sorted}`);




















const quicksort = (arr) => {

    //first my base case, is arr empty or single
    if (arr.length <= 1){
        return arr;
    }


    //if its not empty we will create a pivot and a left and right arr to split the problem up 
    const pivot = arr[0];
    let left = [];
    let right = [];

    //next we will loop through the given array , comparing each element to our pivot
    for (let i = 1 ; i < arr.length ; i++){
        if (arr[i] < pivot){
            left.push(arr[i]);
        }
        else{
            right.push(arr[i]);
        }
    }

    // now we return a recursive call to our function on the left and right sub arrays
    return [...quicksort(left),pivot, ...quicksort(right)];

}



const Arr = [3, 6, 8, 10, 1, 2, 1];
const sorted = quicksort(Arr);
console.log(`sorted array: ${sorted}`);
































