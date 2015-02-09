public class prob1 {
    public static void main(String[] args) {
        // int[] arr={2, 3, 0 , -6, 4, -2, -10, 0, 100};
        int[]arr = {1, 2, -1, 4, 0, 5, -6, -5, -6, 2, 0, 3, -4, 3, -2, 4, -3};
        int prod=1, max=1, max1=1, j=0;

        while(j < arr.length) {
            for (int i = j; i < arr.length; i++) {
                prod = prod * arr[i];
                if(prod>max)
                        max=prod;
            }
            if(max>max1)
                max1=max;
            j++;
            prod=1;
        }
        System.out.println(max1);
    }
}
