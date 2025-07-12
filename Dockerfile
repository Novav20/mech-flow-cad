# Usar la imagen oficial de Microsoft para desarrollo en C++ con vcpkg
FROM mcr.microsoft.com/devcontainers/cpp:1-bookworm

# El entorno ya contiene vcpkg, cmake, git y las herramientas de compilación.

# Establecer el directorio de trabajo dentro del contenedor
WORKDIR /app

# Comando por defecto para mantener el contenedor corriendo
CMD ["tail", "-f", "/dev/null"]