class Livro:

    def __init__(self, id, titulo):
        self.id = id
        self.titulo = titulo
        self.disponivel = True

    def emprestar(self):
        if self.disponivel:
            self.disponivel = False
            print("Livro emprestado com sucesso.")
        else:
            print("Livro indisponível.")

    def devolver(self):
        self.disponivel = True
        print("Livro devolvido.")

    def mostrar(self):
        print(f"ID: {self.id}")
        print(f"Título: {self.titulo}")
        print(f"Disponível: {self.disponivel}")


livro = Livro(1, "Estruturas de Dados")

livro.mostrar()

print()

livro.emprestar()

print()

livro.mostrar()

print()

livro.devolver()

print()

livro.mostrar()