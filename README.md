# Image-processing-using-Qt-and-OpenCV
This is an application that i designed and developped using Qt and OpenCV, 

 At the beginning I had the idea to implement the following specifications : 
 
    - The application must be able to take an image as an input (*.jpg,*.png,*.bmp) 
    - The application must be able to apply a blur filter. 
    - The user must be able to choose the Median Blur or the Gaussian Blur type to filter the input image.
    - The application must be able to save the output image (*.jpg, *.png,*.bmp)
    
![First_version](https://user-images.githubusercontent.com/96794946/147852291-5c9f2daa-0806-4977-b37e-dd79a8aa74fb.png)

After I validated the first version of the application, I decided to add a sobel filter that allows to detect the contours

![Add_Sobel_filter](https://user-images.githubusercontent.com/96794946/147852324-13681283-2f87-49c1-8143-379c94bc618d.png)

Finally I added two boxes to display the input and output images :

![Last version](https://user-images.githubusercontent.com/96794946/147852325-d35084d6-1362-43f6-a51b-41c4277d322e.png)
