from PIL import Image

def encrypt_image(image_path, key):
    # Open the image
    image = Image.open(image_path)
    # Get the dimensions of the image
    width, height = image.size
    # Load the image into a pixel array
    pixels = image.load()

    # Encrypt the image by applying XOR operation with the key to each pixel
    for y in range(height):
        for x in range(width):
            r, g, b = pixels[x, y]
            r ^= key
            g ^= key
            b ^= key
            pixels[x, y] = (r, g, b)

    # Save the encrypted image
    encrypted_image_path = "encrypted_" + image_path
    image.save(encrypted_image_path)
    print("Image encrypted successfully!")
    return encrypted_image_path

def decrypt_image(encrypted_image_path, key):
    # Open the encrypted image
    image = Image.open(encrypted_image_path)
    # Get the dimensions of the image
    width, height = image.size
    # Load the image into a pixel array
    pixels = image.load()

    # Decrypt the image by applying XOR operation with the key to each pixel
    for y in range(height):
        for x in range(width):
            r, g, b = pixels[x, y]
            r ^= key
            g ^= key
            b ^= key
            pixels[x, y] = (r, g, b)

    # Save the decrypted image
    decrypted_image_path = "decrypted_" + encrypted_image_path[len("encrypted_"):]
    image.save(decrypted_image_path)
    print("Image decrypted successfully!")
    return decrypted_image_path

# Example usage
image_path = "example_image.jpg"
key = 123  # Key for encryption and decryption
encrypted_image_path = encrypt_image(image_path, key)
decrypted_image_path = decrypt_image(encrypted_image_path, key)
import os


