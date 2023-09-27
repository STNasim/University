    def __procesar_y_avisar_progreso(self):
        pipeline = Pipeline(self.__ruta, self.__lista_muestras, self.__grupos, self.__grupo_control,
                                            self.dsbox_error_sondas.value(), self.dsbox_error_genes.value(),
                                            self.check_multimappers.isChecked())
        
        Avisos.avisar_procesando("Cargando muestras...")
        QApplication.processEvents()
        pipeline.cargar_muestras()

        Avisos.avisar_procesando("Procesando muestras...")
        QApplication.processEvents()
        pipeline.procesar_muestras()

        Avisos.avisar_procesando("Generando reporte de calidad de muestras...")
        QApplication.processEvents()
        if self.check_reporte_calidad.isChecked():
            pipeline.generar_reporte_muestras()
            figuras_reporte_muestras = pipeline.obtener_figuras_reporte_muestras()
            self.__ventana_reporte_muestras = \
            VentanaGraficos.poner_figuras_ventana(figuras_reporte_muestras, "Reporte muestras")

            self.__ventana_reporte_muestras.showMaximized()

        Avisos.avisar_procesando("Procesando sondas...")
        QApplication.processEvents()
        pipeline.procesar_sondas()

        Avisos.avisar_procesando("Procesando genes...")
        QApplication.processEvents()
        pipeline.procesar_genes()

        Avisos.avisar_procesando("Calculando expresión...")
        QApplication.processEvents()
        pipeline.calcular_expresion()

        Avisos.avisar_procesando("Generando reporte de calidad de limma...")
        QApplication.processEvents()
        if self.check_reporte_calidad.isChecked():
            pipeline.generar_reporte_limma()
            figuras_reporte_limma = pipeline.obtener_figuras_reporte_limma()
            self.__ventana_reporte_limma = \
            VentanaGraficos.poner_figuras_ventana(figuras_reporte_limma, "Reporte Limma")

            self.__ventana_reporte_limma.showMaximized()

        Avisos.avisar_procesando("Enriqueciendo datos...")
        QApplication.processEvents()
        pipeline.enriquecer_datos()

        pipeline.guardar_datos()
        Avisos.avisar_finalizado("Procesamiento finalizado")