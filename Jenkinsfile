pipeline {
	agent {
		docker {
			image 'conanio/gcc7'
			args '-v /tmp/conan/.conan:/home/conan/.conan'
		}
	}

	options {
		skipStagesAfterUnstable() 
	}

	environment {
		COMMIT_ID = ""
		RESULTADO = ""
	}

	stages{
		stage('Preparacion') {
			steps {
				script {
					checkout scm
					sh "git rev-parse --short HEAD > .git/commit_id"
					COMMIT_ID = readFile('.git/commit_id').trim()
				}
			}
		}

		stage('Dependencias') {
			steps {
				script {
					try {
						sh 'mkdir build && cd build && conan install ..'
						RESULTADO = "Se han obtenido las dependencias del proyecto"
					} catch( Exception err ) {
						currentBuild.result = 'FAILURE'
						RESULTADO = "Se ha generado un error: ${err}: al momento de obtener las dependencias del binario calculador"
						
						office365ConnectorSend message: "${COMMIT_ID}: ${RESULTADO}", status:"${currentBuild.result}", webhookUrl:"${DEV_UXPOS_WEBHOOK}"
						sh 'exit 1'		
					}
				}
			}
		}
		
		stage('Compilacion') {
			steps {
				script {
					try {
						sh 'cd src && make'
						RESULTADO = "Se ha compilado localmente la libreria operaciones/0.1.1@uxpos/stable"
					} catch( Exception err ) {
						currentBuild.result = 'FAILURE'
						RESULTADO = "Se ha generado un error: ${err} : al momento de compilar el binario calculador"

						office365ConnectorSend message: "${COMMIT_ID}: ${RESULTADO}", status:"${currentBuild.result}", webhookUrl:"${DEV_UXPOS_WEBHOOK}"
						sh 'exit 1'
					}
				}
			}
		}

		stage('Pruebas') {
			steps {
				script {
					try {
						sh 'cd src && test/src/test'
						RESULTADO = "Se han ejecutado correctamente las pruebas del binario calculador"
					} catch( Exception err ) {
						currentBuild.result = 'FAILURE'
						RESULTADO = "Se ha generado un error: ${err} : no ha pasado las pruebas unitarias del binario calculador"

						office365ConnectorSend message: "${COMMIT_ID}: ${RESULTADO}", status:"${currentBuild.result}", webhookUrl:"${DEV_UXPOS_WEBHOOK}"
						sh 'exit 1'
					}
				}
			}
		}

		stage('Subida') {
			steps {
				script {
					try {
						sh 'cp src/calculador .'
						RESULTADO = "Se ha generado el binario calculador"
						currentBuild.result = 'SUCCESS'
					} catch( Exception err ) {
						currentBuild.result = 'FAILURE'
						RESULTADO = "Se ha generado un error: ${err} : al momento de subir libreria operaciones/0.1.1@uxpos/stable a conan-repo"
					}

					office365ConnectorSend message: "${COMMIT_ID}: ${RESULTADO}", status:"${currentBuild.result}", webhookUrl:"${DEV_UXPOS_WEBHOOK}"
				}
			}
		}

		stage('Limpieza') {
			steps {
				script {
					try {
						sh 'cd src/test/src && make clean'
						sh 'cd src && make clean'
						sh 'rm -rf build'

						RESULTADO = "Se eliminaron correctamente las carpetas temporales"
					} catch( Exception err ) {
						RESULTADO = "Se ha generado un error: ${err} : al momento de subir libreria operaciones/0.1.1@uxpos/stable a conan-repo"
					}
				}
			}
		}
	}
}
