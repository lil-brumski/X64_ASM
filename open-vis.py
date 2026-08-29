import cv2

print(cv2.__version__)

path = str(input("Enter image path: "))
image = cv2.imread(path)

cv2.imshow("Hello", image)
cv2.waitKey(0)
