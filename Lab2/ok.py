def lagrange_interpolation(x_values, y_values, x):
    n = len(x_values)
    result = 0.0
    
    for i in range(n):
        term = y_values[i]
        for j in range(n):
            if i != j:
                term *= (x - x_values[j]) / (x_values[i] - x_values[j])
        result += term
    
    return result

# Przykładowe dane wejściowe
x_values = [1, 2, 3, 4, 5]
y_values = [2, 1, 3, 2, 4]

# Punkty, w których obliczamy wartości wielomianu interpolacyjnego
x_interpolate = [2.5, 3.5]

for x in x_interpolate:
    result = lagrange_interpolation(x_values, y_values, x)
    print(f"P({x}) = {result}")
