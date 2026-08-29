# A I  A S S I S T E D
import cv2

# 1. Initialize the camera (0 is usually the default built-in webcam)
cap = cv2.VideoCapture(0)

# Check if the webcam opened successfully
if not cap.isOpened():
    print("Error: Could not open the camera.")
    exit()

print("Camera stream started. Press 'q' to quit.")

while True:
    # 2. Capture frame-by-frame
    # 'ret' is a boolean (True if frame was read correctly), 'frame' is the image array
    ret, frame = cap.read()

    # If the frame was not grabbed properly, break the loop
    if not ret:
        print("Error: Failed to grab frame.")
        break

    # 3. Display the resulting frame in a window named 'Camera Feed'
    cv2.imshow('Camera Feed', frame)

    # 4. Wait for 1 millisecond and check if the user pressed the 'q' key to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 5. When everything is done, release the capture and destroy all windows
cap.release()
cv2.destroyAllWindows()
