# Punto y Fama (C++)

Un juego de consola para adivinar un número de **4 dígitos sin repetir**, inspirado en “Punto y Fama”. Permite dos modos: el programa genera el número aleatoriamente o el usuario define el número secreto para que otra persona lo adivine.

---

## 📁 Estructura del proyecto

```
.
├── main.cpp
├── utilidades.h
└── utilidades.cpp
```

- **`main.cpp`**: muestra el menú, orquesta el flujo y ejecuta las rondas de intentos.  
- **`utilidades.h`**: declara la clase `utilidades` con funciones estáticas.  
- **`utilidades.cpp`**: implementa la lógica: generar número, convertir intento a arreglo, contar *famas* y *puntos*.

---

## 🎮 Reglas rápidas

- **Fama**: aciertas **dígito y posición**.  
- **Punto**: aciertas **dígito** pero está en **otra posición**.  
- **Ganas** cuando obtienes **4 famas**.

Ejemplo:  
Secreto = `4279`  
Intento = `4720` → Famas: 1 (el `7` no está en su sitio), Puntos: 2 (`4` y `2` están pero en otra posición).

> Nota: el programa acepta cualquier número de 4 cifras como intento (sin dígitos repetidos).

---

## 🧠 Arquitectura y API de utilidades

**Clase `utilidades` (estática):**

- `array<int,4> generarNumero()`  
  Genera un arreglo de 4 dígitos **sin repetir** (0–9).

- `array<int,4> obtenerNumero(int numeroUsuario)`  
  Convierte un entero (p. ej., `1234`) en `{1,2,3,4}`.

- `int confirmarFama(array<int,4> nGanador, array<int,4> nUsuario)`  
  Cuenta cuántos índices `i` cumplen `nGanador[i] == nUsuario[i]`.

- `int confirmarPunto(array<int,4> nGanador, array<int,4> nUsuario)`  
  Cuenta coincidencias de dígitos **entre ambos arreglos**.

---

## 🔍 Detalles de implementación

- **Aleatoriedad**: se usa `std::random_device`, `std::mt19937` y `std::uniform_int_distribution` para generar dígitos uniformes en `[0,9]`.
- **Unicidad de dígitos**: al llenar el arreglo del número secreto se evita repetir un dígito ya presente.
- **Conversión de intentos**: si el usuario escribe menos de 4 cifras, se anteponen ceros (p. ej., `57` → `{0,0,5,7}`).

---

## 👥 Autoría

- Thomas Serna Saldarriaga
