import math

def newton_method(x0, epsilon, stop):

    def f(x):
        return math.sin(x) - x / 2

    def df(x):
        return math.cos(x) - 0.5

    x = x0
    i = 0

    while i in range(stop):
        x_next = x - f(x) / df(x)

        print(f"Iteracja {i + 1}: x = {x_next:.4f}, f(x) = {f(x_next):.4f}")

        if abs(f(x_next)) < epsilon:
            print("Przyblizona wartosc pierwiastka: ", x_next)
            print("Liczba iteracji: ", i + 1)
            return

        x = x_next
        i += 1

    print(f"Nie znaleziono rozwiazania dla {stop} iteracji.")

if __name__ == "__main__":
    x0 = float(input("Podaj punkt startowy (x0): "))
    epsilon = float(input("Podaj dokładność (epsilon): "))
    stop = int(input("Podaj maksymalna liczbe iteracji: "))

    newton_method(x0, epsilon, stop)
