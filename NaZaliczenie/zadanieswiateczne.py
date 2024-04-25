import numpy as np

def metoda_euler(b, n):
  f = lambda x, y: y ** 2 / (x + 1)
  a = 0
  y0 = 3
  h = (b - a) / n
  y = np.zeros(n + 1)
  y[0] = y0
  for i in range(n):
    y[i + 1] = y[i] + h * f(a + i * h, y[i])
  return y[n]

def metoda_heuna(b,n):
  f = lambda x, y: y / x ** 2
  a = 1
  y0 = 2
  h = (b - a) / n
  y = np.zeros(n + 1)
  y[0] = y0
  for i in range(n):
    k1 = f(a + i * h, y[i])
    k2 = f(a + i * h + h, y[i] + h * k1)
    y[i + 1] = y[i] + h * (k1 + k2) / 2
  return y[n]

def metoda_zmodyfikowana_euler(b,n):
  f = lambda x, y: 2 * x * y
  a = 0
  y0 = 1
  h = (b - a) / n
  y = np.zeros(n + 1)
  y[0] = y0
  for i in range(n):
    k1 = f(a + i * h, y[i])
    y[i + 1] = y[i] + h * k1
  return y[n]

if __name__ == "__main__":
  n = int(input("Podaj n: \n"))
  b = float(input("Podaj b: \n"))
  wybor = int(input("Wybierz zadanie: \n 1. Euler \n 2. Heun \n 3. Zmodyfikowany Euler \n"))
  
  if wybor == 1:
    y_euler = metoda_euler(b,n)
    print(f"f({b}):", y_euler)
  elif wybor == 2:
    y_heuna = metoda_heuna(b,n)
    print(f"f({b}):", y_heuna)
  elif wybor == 3:
    y_mod_euler = metoda_zmodyfikowana_euler(b,n)
    print(f"f({b}):", y_mod_euler)
  else:
    print("Nie ma takiego zadania")