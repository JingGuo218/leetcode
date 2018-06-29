/*************************************************************************************** 
Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
Author : Jing Kuo

Description:
    Given two arrays, write a function to compute their intersection.

Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Complexity:
    Time:O(max(n,m))
    Space:O(min(n,m))

Beats: 100% 

Approach: Hash, note following code is not clean enough
          There are three to-to can be done

Follow up:
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

***************************************************************************************/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HashSize 1024
struct HashNode{
    int key;
    int cnt;
    struct HashNode* next;
}Hash[HashSize]; 
//to-do: should use malloc

void hashInit(){
    for(int i=0;i<HashSize;i++){
        Hash[i].key=0;
        Hash[i].cnt=0;
        Hash[i].next=NULL;
    }
}

void hashAdd(int num){
    int hashCode=abs(num%HashSize);

    if (Hash[hashCode].cnt==0){
        Hash[hashCode].key=num;
        Hash[hashCode].cnt=1;
        return;
    }
          
    struct HashNode* ptrHash= &Hash[hashCode]; 
     
    do{
        if ((ptrHash->key)==num ){
            ptrHash->cnt+=1;
            return;
        }
        ptrHash=ptrHash->next;
    }while( (ptrHash->next) !=NULL);

    ptrHash->next=malloc(sizeof(struct HashNode));
    ptrHash = ptrHash->next;
    ptrHash->key=num;
    ptrHash->cnt=1;
    ptrHash->next=NULL;      

    return;
}

bool hashRemove(int num){
    int hashCode=abs(num%HashSize);
    struct HashNode* ptrHash= &Hash[hashCode]; 
    
    while( ptrHash!=NULL){
        if ((ptrHash->key)==num ){
            if (ptrHash->cnt!=0){
                ptrHash->cnt-=1;
                return true;
            }
            //to-do if cnt:1 -> 0 should free this node
        }
        ptrHash=ptrHash->next;
    }
    
    return false;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* numsSmall, *numsBig;
    int numsSizeSmall,numsSizeBig;
    int* retArray;
    int retArrayIdx=0;
    
    if((nums1Size==0)||(nums2Size)==0){
        *returnSize=0;
        return NULL;
    }
    
    if(nums1Size > nums2Size){
        numsSmall=nums2;
        numsBig=nums1;
        numsSizeSmall = nums2Size;
        numsSizeBig = nums1Size;
    }else{
        numsSmall=nums1;
        numsBig=nums2;
        numsSizeSmall = nums1Size;
        numsSizeBig = nums2Size;
    }    
    
    retArray=malloc(sizeof(int)*numsSizeSmall);
    
    hashInit();
    
    for(int i=0;i<numsSizeSmall;i++){
        hashAdd(numsSmall[i]);
    }
    
    for(int i=0;i<numsSizeBig;i++){
        if (hashRemove(numsBig[i])){
            retArray[retArrayIdx]=numsBig[i];
            retArrayIdx++;
            if (retArrayIdx==numsSizeSmall) break;
        }
    }
    
    //to-do: allocated array can be resize 
    
    *returnSize=retArrayIdx;
    return retArray;
}