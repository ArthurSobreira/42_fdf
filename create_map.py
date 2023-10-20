from PIL import Image
import numpy as np

image_path = input("Enter the image path: ")
imagem = Image.open(image_path)
width, height = imagem.size

image_matrix = np.array(imagem)

relief_map = np.zeros((height, width))

for i in range(height):
    for j in range(width):
        height = int(np.mean(image_matrix[i, j])) - 128
        relief_map[i, j] = height

save_image = input("Enter how to save the map: ")
np.savetxt(save_image, relief_map, fmt='%d')
