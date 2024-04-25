import math

def householder(size):
    vector = []

    for i in range(size):
        x_i = int(input(f"Podaj współrzędną x[{i}]: "))
        vector.append(x_i)

    squares_sum = 0.0
    for element in vector:
        squares_sum += element**2
    norm = math.sqrt(squares_sum)

    sign_a = -1 if vector[0] < 0 else 1 if vector[0] > 0 else 0

    t = -sign_a * norm

    print("Po wykonanej transformacji otrzymujemy wektor:")
    print(t)
    for i in range(1, size):
        print(0)

if __name__ == "__main__":
    size = int(input("Podaj rozmiar wektora: "))
    householder(size)
