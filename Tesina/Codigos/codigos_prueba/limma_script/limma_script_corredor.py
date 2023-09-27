import subprocess
import os

class LimmaScriptCorredor:
    def correr_script(path_archivo_entrada = "genes.tsv", path_archivo_salida = "resultados.tsv",
                      path_Rscript = "Rscript", path_limma_script = "limma_script.R") -> bool:
        
        subprocess.run([path_Rscript, path_limma_script, path_archivo_entrada,path_archivo_salida])
        
        if os.path.isfile(path_archivo_salida):
            return True
        else:
            return False

if __name__ == "__main__":
    print(LimmaScriptCorredor.correr_script("datos/agrupado3.tsv", path_limma_script = "src/limma_script.R"))