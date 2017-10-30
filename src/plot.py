#! /usr/bin/env python

import matplotlib
matplotlib.use('GTKAgg')
import matplotlib.pyplot as plt
import numpy as np
import time

plotters = {'background':0, 'qui':0, 'surf':0}

def getSize(varsPath):
    size = 0
    with open(varsPath) as inFile:
        for lines in inFile:
            lines = lines.rsplit()
            # print lines
            for terms in lines:
                if terms == "size":
                    currentIndex = lines.index("size")
                    size = lines[currentIndex + 2]
                    size = int(size[:-1])
                else:
                    pass
    return size

def getMFromDataFile(dataPath, size):
    with open(dataPath) as inFile:
        Mx = np.zeros(size)
        My = np.zeros(size)
        Mz = np.zeros(size)
        index = 0
        for lines in inFile:
            try:
                lines = lines.rsplit()
                Mx[index] = float(lines[0])
                My[index] = float(lines[1])
                Mz[index] = float(lines[2])
                index += 1
            except:
                pass
    return Mx, My, Mz

def initPlot():
    fig = plt.figure()
    ax = fig.add_subplot(111)

    plotters['qui'] = ax.quiver(Mx, My, Mz, color = '#220c5f')
    plotters['background'] = fig.canvas.copy_from_bbox(ax.bbox)

    fig.show()
    fig.canvas.draw()


def updatePlot():
    fig = plt.gcf()
    ax = fig.add_subplot(111)

    fig.canvas.restore_region(plotters['background'])

    plotters['qui'].set_UVC(Mx, My)

    ax.draw_artist(plotters['qui'])

    fig.canvas.blit(ax.bbox)

if __name__ == "__main__":
    varsPath = "src/vars.cpp"

    dataPath = "build/dataFile.dat"

    size = getSize(varsPath)

    Mx, My, Mz = getMFromDataFile(dataPath, size)

    initPlot()

    while(True):
        Mx, My, Mz = getMFromDataFile(dataPath, size)
        updatePlot()
        time.sleep(0.25)

