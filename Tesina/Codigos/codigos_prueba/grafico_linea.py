from grafico_base import GraficoBase

class GraficoLinea(GraficoBase):
    def crear_y_devolver_figura(self):
        ax = self._datos.plot(x=0, y=[i for i in range(1, self._datos.shape[1])])      

        self._colocar_valores_eje(ax)

        fig = ax.get_figure()

        return fig
    
if __name__ == '__main__':
    #Linea
    '''
    data = {'Días': ['L', 'M', 'X', 'J', 'V', 'S', 'D'],
        'Madrid': [28.5, 30.5, 31, 30, 28, 27.5, 30.5],
        'Barcelona': [24.5, 25.5, 26.5, 25, 26.5, 24.5, 25]}
    df = pd.DataFrame(data)
    grafico = graficador.crear_grafico("linea", df, "Diagrama de linea", "Días", "Valor")
    grafico.mostrar_grafico() 
    '''