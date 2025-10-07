# Punto y Fama (C++)

Juego de consola para adivinar un número de 4 dígitos sin repetir (Punto y Fama). Incluye sistema de usuarios con estadísticas y configuración persistente (intentos máximos y modo de generación del número).

---

## 🚀 Funcionalidades

- **Juego base (Punto y Fama)**  
  El objetivo es adivinar un número de 4 dígitos (todos distintos).  
  - **Fama**: aciertas **dígito y posición**.  
  - **Punto**: aciertas **dígito** pero en **otra posición**.  
  - Ganas cuando obtienes **4 famas**.

- **Sistema de usuarios (login por nombre)**  
  Al iniciar, se solicita un **nombre de usuario**. El sistema carga (o crea) tu perfil y **acumula estadísticas** por jugador:
  - Partidas ganadas y perdidas
  - Porcentaje de victoria
  - Promedio de intentos en partidas ganadas
  - Historial de intentos usados en cada victoria

- **Persistencia de usuarios (CSV)**  
  Se guardan todos los usuarios en `usuarios.csv` con el formato:
  ```
  nombre,ganadas,perdidas,intento1/intento2/intento3/...
  ```

- **Configuración persistente**  
  Se guarda en `config.txt`:
  1. **Intentos máximos por ronda** (`-1` = sin límite)
  2. **Número generado aleatoriamente** (`1` = Sí, `0` = No)

- **Menú de juego con 4 opciones**  
  1) Empezar a jugar  
  2) Aprender a jugar (mini-guía)  
  3) Ver estadísticas del usuario activo  
  4) Configuración del juego (cambiar intentos máximos y si el número se genera aleatoriamente)

---

## 📁 Estructura del proyecto

```
.
├── main.cpp                      # Flujo principal, menús y bucle del juego
├── utilidades.h
├── utilidades.cpp                # Lógica de juego: generar, convertir, famas, puntos
├── usuario.h
├── usuario.cpp                   # Modelo de usuario y métricas/estadísticas
├── persistenciaUsuario.h
├── persistenciaUsuario.cpp       # Carga/guarda usuarios en CSV
├── configuracion.h
├── configuracion.cpp             # Carga/guarda configuración en archivo de texto
├── README.md                     # Este archivo
├── config.txt                    # Archivo de configuración (2 líneas)
└── usuarios.csv                  # Base de datos de usuarios (CSV)
```

---

## 🧠 Detalles de la lógica

### Utilidades del juego
- `generarNumero()` → genera 4 dígitos **sin repetir** (0–9).  
- `obtenerArreglo(int)` → convierte `1234` en `{1,2,3,4}`.  
- `obtenerNumero(array<int,4>)` → convierte `{1,2,3,4}` en `1234`.  
- `confirmarFama(...)` → cuenta coincidencias **dígito+posición**.  
- `confirmarPunto(...)` → cuenta coincidencias de **dígitos en posiciones distintas**.

### Configuración
- Archivo **`config.txt`** (dos líneas):  
  1) `intentosMax` (`-1` = sin límite).  
  2) `numAleatorio` (`1` = Sí, `0` = No).  
- Desde el menú **Configuración** puedes editar ambos valores.  
- El sistema guarda los cambios automáticamente.

### Usuarios y estadísticas
- Al iniciar, se pide **nombre de usuario** y se carga su perfil.  
- Se registran:
  - **Ganadas** y **perdidas**  
  - **% de victoria** = `ganadas * 100 / (ganadas + perdidas)`  
  - **Promedio de intentos (solo en victorias)**  
  - **Lista de intentos** de cada ronda ganada  
- Al finalizar cada partida, se pregunta si deseas **ver tus estadísticas**.  
- Los datos se guardan al disco cuando termina la partida o cambias de configuración.

---

## 💾 Archivos de datos

### `config.txt` (texto plano)
```
-1
1
```
- Línea 1: `-1` → sin límite de intentos. Usa un entero distinto de `-1` para fijar un máximo.  
- Línea 2: `1` → el número a adivinar se genera automáticamente. Usa `0` para ingresar manualmente el número secreto.

> **Sugerencia:** Si el archivo no existe, créalo con los dos valores anteriores la primera vez que ejecutes.

### `usuarios.csv` (CSV)
Formato por línea:
```
nombre,ganadas,perdidas,intento1/intento2/...
```
- El historial de intentos se separa por `"/"` y puede estar vacío si aún no hay victorias.

---

## 🕹️ Flujo de juego (resumen)

1. Al iniciar, se cargan `config.txt` y `usuarios.csv`.  
2. Inicias sesión escribiendo tu **nombre de usuario**.  
3. Menú principal: jugar, guía, estadísticas, configuración.  
4. Si eliges **Jugar**:  
   - Si está activo **número aleatorio**, se genera automáticamente.  
   - Si **no**, se te pedirá ingresar el número secreto (para que otro jugador lo adivine).  
   - En cada intento escribes un número de 4 dígitos; verás **Famas** y **Puntos**.  
   - Ganas al llegar a **4 Famas** o pierdes si alcanzas el límite de intentos.  
   - Tras terminar, puedes **ver tus estadísticas** y se **guardan** tus datos.

---

## 📌 Notas y consideraciones

- El valor `-1` en intentos significa **sin límite**.  
- Si usas número **manual** (configuración), asegúrate de **no repetir dígitos** en el secreto.  
- El archivo `usuarios.csv` se **reescribe completo** en cada guardado con el estado actual de los usuarios.  

---

## 👤 Autor

- Thomas Serna Saldarriaga
