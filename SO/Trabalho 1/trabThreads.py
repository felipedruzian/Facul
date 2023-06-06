import multiprocessing as mp
import time
import matplotlib.pyplot as plt
import numpy as np
import csv

MAX = 10000000 # tamanho do intervalo
N = 5 # numero de repetições do experimento

resul_singlecore = 0
resul_multicore = 0
PI = 3.14159265358979323846

def pi(q, min, max):
    resultado = 0
    for n in range(min, max):
        calculo = (-1)**n / (2*n+1)
        resultado += calculo
    q.put(resultado*4)

def singlecore(nInteracoes):
    global resul_singlecore
    t1 = time.time()
    q = mp.Queue()
    p = mp.Process(target=pi, args=(q, 0, nInteracoes))
    p.start()
    resul_singlecore = q.get()
    t2 = time.time()
    return (t2 - t1)

def multicore(nInteracoes, nThreads):
    global resul_multicore
    resul_multicore = 0
    t1 = time.time()
    q = mp.Queue()
    for i in range(nThreads):
        min_ = int(i*nInteracoes/nThreads)
        max_ = int((i+1)*nInteracoes/nThreads)
        p = mp.Process(target=pi, args=(q, min_, max_))
        p.start()

    for i in range(nThreads):
        resul_multicore += q.get()
    t2 = time.time()
    return (t2 - t1)

if __name__ == '__main__':

    interacoes = int(input('Digite o número de interações: '))
    threads = int(input('Digite o número de threads: '))
    repeticoes = int(input('Digite o número de repetições: '))

    ts = [] #tempo singlecore
    tm = [] #tempo multicore
    tg = [] #tempo ganho
    tspeedup = [] #speedup
    teff = [] #eficiencia

    ms = [] #media singlecore
    mm = [] #media multicore
    mg = [] #media ganho
    mspeedup = [] #media speedup
    meff = [] #media eficiencia

    ds = [] #desvio singlecore
    dm = [] #desvio multicore
    dg = [] #desvio ganho
    dspeedup = [] #desvio speedup
    deff = [] #desvio eficiencia

    vs = [] #variancia singlecore
    vm = [] #variancia multicore
    vg = [] #variancia ganho
    vspeedup = [] #variancia speedup
    veff = [] #variancia eficiencia

    x = range(1,repeticoes+1)

    for j in range(1, threads+1):
        for i in range (repeticoes):
            print('    Threads = ', j)
            print('  Repetição = ', i+1)

            ts.append(singlecore(interacoes))
            print ('Resultado siglecore = ', resul_singlecore)
            erro = PI - resul_singlecore
            print ('Erro singlecore = ', erro)
            print('Tempo singlecore = %.3fs' % ts[i])
            print(' ')

            tm.append(multicore(interacoes, j))
            print ('Resultado multicore = ', resul_multicore)
            erro = PI - resul_multicore
            print ('Erro multicore = ', erro)
            print('Tempo multicore = %.3fs' % tm[i])
            print(' ')
            
            tg.append(ts[i] - tm[i])
            tspeedup.append(ts[i]/tm[i])
            teff.append(100 * tspeedup[i]/j)
            print('Tempo ganho = %.3fs' % tg[i])
            print('Speedup = %.2f' % tspeedup[i])
            print('Eficiencia = %.2f' % teff[i])
            print('------------------------')

        ms.append(np.average(ts))
        mm.append(np.average(tm))
        mg.append(np.average(tg))
        mspeedup.append(np.average(tspeedup))
        meff.append(np.average(teff))

        ds.append(np.std(ts))
        dm.append(np.std(tm))
        dg.append(np.std(tg))
        dspeedup.append(np.std(tspeedup))
        deff.append(np.std(teff))

        vs.append(np.var(ts))
        vm.append(np.var(tm))
        vg.append(np.var(tg))
        vspeedup.append(np.var(tspeedup))
        veff.append(np.var(teff))

        print('Média singlecore = %.3fs' % np.average(ts))
        print('Média multicore = %.3fs' % np.average(tm))
        print('Média ganho = %.3fs' % np.average(tg))
        print('Média speedup = %.2f'% np.average(tspeedup))
        print('Média eficiencia = %.2f'% np.average(teff))
        #print(' ')
        #print('Variancia singlecore = ', np.var(ts))
        #print('Variancia multicore = ', np.var(tm))
        #print('Variancia ganho = ', np.var(tg))
        #print('Variancia speedup = ', np.var(tspeedup))
        #print('Variancia eficiencia = ', np.var(teff))
        #print(' ')
        #print('Desvio singlecore = ', np.std(ts))
        #print('Desvio multicore = ', np.std(tm))
        #print('Desvio ganho = ', np.std(tg))
        #print('Desvio speedup = ', np.std(tspeedup))
        #print('Desvio eficiencia = ', np.std(teff))
        print('------------//------------')

        # Plots por repeticoes

        #plt.plot(x, ts, label='Singlecore', marker='o')
        #plt.plot(x, tm, label='Multicore', marker='.')
        #plt.xlabel('Repetições')
        #plt.ylabel('Tempo (s)')
        #plt.title('Threads = ' + str(j), loc='left')
        #plt.grid()
        #plt.legend()
        #plt.show()

        #plt.plot(x, tg, label='Ganho', marker='o')
        #plt.xlabel('Repetições')
        #plt.ylabel('Tempo (s)')
        #plt.title('Threads = ' + str(j), loc='left')
        #plt.grid()
        #plt.legend()
        #plt.show()

        #plt.plot(x, tspeedup, label='Speedup', marker='o')
        #plt.xlabel('Repetições')
        #plt.ylabel('Numero de vezes melhor que singlecore')
        #plt.title('Threads = ' + str(j), loc='left')
        #plt.grid()
        #plt.legend()
        #plt.show()

        #plt.plot(x, teff, label='Eficiencia', marker='o')
        #plt.xlabel('Repetições')
        #plt.ylabel('Eficiencia por core (%)')
        #plt.title('Threads = ' + str(j), loc='left')
        #plt.grid()
        #plt.legend()
        #plt.show()

        ts.clear()
        tm.clear()
        tg.clear()
        tspeedup.clear()
        teff.clear()


    # Plots FINAIS por threads

    plt.plot(range(1,threads+1), ms, label='Singlecore', marker='o')
    plt.plot(range(1,threads+1), mm, label='Multicore', marker='o')
    #plt.plot(range(1,threads+1), ds, label='Desvio singlecore', marker='*')
    #plt.plot(range(1,threads+1), dm, label='Desvio multicore', marker='*')
    #plt.plot(range(1,threads+1), vs, label='Variancia singlecore', marker='.')
    #plt.plot(range(1,threads+1), vm, label='Variancia multicore', marker='.')
    plt.xlabel('Threads')
    plt.ylabel('Tempo (s)')
    plt.title('Média de tempo')
    plt.grid()
    plt.legend()
    plt.show()

    plt.plot(range(1,threads+1), mg, label='Ganho', marker='o')
    #plt.plot(range(1,threads+1), dg, label='Desvio ganho', marker='*')
    #plt.plot(range(1,threads+1), vg, label='Variancia ganho', marker='.')
    plt.xlabel('Threads')
    plt.ylabel('Tempo (s)')
    plt.title('Média de ganho')
    plt.grid()
    plt.legend()
    plt.show()

    plt.plot(range(1,threads+1), mspeedup, label='Speedup', marker='o')
    #plt.plot(range(1,threads+1), dspeedup, label='Desvio speedup', marker='*')
    #plt.plot(range(1,threads+1), vspeedup, label='Variancia speedup', marker='.')
    plt.xlabel('Threads')
    plt.ylabel('Numero de vezes melhor que singlecore')
    plt.title('Média de speedup')
    plt.grid()
    plt.legend()
    plt.show()

    plt.plot(range(1,threads+1), meff, label='Eficiencia', marker='o')
    #plt.plot(range(1,threads+1), deff, label='Desvio eficiencia', marker='*')
    #plt.plot(range(1,threads+1), veff, label='Variancia eficiencia', marker='.')
    plt.xlabel('Threads')
    plt.ylabel('Eficiencia por core (%)')
    plt.title('Média de eficiencia')
    plt.grid()
    plt.legend()
    plt.show()

    with open('resultados.csv', 'w') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['Threads', 'Media Singlecore', 'Desvio Singlecore', 'Variancia Singlecore', 'Media Multicore', 'Desvio Multicore', 'Variancia Multicore', 'Media Ganho', 'Desvio Ganho', 'Variancia Ganho', 'Media Speedup', 'Desvio Speedup', 'Variancia Speedup', 'Media Eficiencia', 'Desvio Eficiencia', 'Variancia Eficiencia'])
        for i in range(threads):
            csvwriter.writerow([i+1, ms[i], ds[i], vs[i], mm[i], dm[i], vm[i], mg[i], dg[i], vg[i], mspeedup[i], dspeedup[i], vspeedup[i], meff[i], deff[i], veff[i]])
        

