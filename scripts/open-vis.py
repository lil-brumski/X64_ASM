"""@package Omo
"""
import cv2

print(cv2.__version__)

"""@brief Guide
"""
class Learn:
    """#@add_toggle_python Obtain
    @brief Hey
    @end_toggle
    """
    def Version():
        print("Hello Gang")

path = str(input("Enter image path: "))
image = cv2.imread(path)

cv2.imshow("Hello", image)
cv2.waitKey(0)
