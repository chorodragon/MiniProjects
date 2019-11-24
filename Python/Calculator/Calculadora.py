print ("Calculadora")
print ("1. Suma")
print ("2. Resta")
print ("3. Multiplicacion")
print ("4. Division")
op = input("Ingrese el numero de la opcion que desea: ");

a = int(input("Ingrese el primer termino: "))
b = int(input("Ingrese el segundo termino: "))

if op == '1':
    c = a + b
elif op == '2':
    c = a - b
elif op == '3':
    c = a * b
elif op == '4':
    c = a / b
else:
    print ("La opcion no es valida")

print ("El resultado es: ",c)

exit()
