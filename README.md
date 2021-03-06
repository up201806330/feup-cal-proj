# PortoCityTransfers <!-- {#mainpage} -->

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

![Compile reports](https://github.com/dmfrodrigues/feup-cal-proj/workflows/Compile%20reports/badge.svg)
![Test](https://github.com/dmfrodrigues/feup-cal-proj/workflows/Test/badge.svg)

- **Project name:** PortoCityTransfers
- **Short description:** Console-based program to manage a shuttle company
- **Environment:** Unix/Windows console
- **Tools:** C++
- **Institution:** [FEUP](https://sigarra.up.pt/feup/en/web_page.Inicial)
- **Course:** [CAL](https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=436441) (Algorithm Design and Analysis)
- **Project grade:** 19.2/20.0
- **Group members:**
    - [Diogo Miguel Ferreira Rodrigues](https://github.com/dmfrodrigues) (<dmfrodrigues2000@gmail.com> / <diogo.rodrigues@fe.up.pt>)
    - [João António Cardoso Vieira e Basto de Sousa](https://github.com/JoaoASousa) (<up201806613@fe.up.pt>)
    - [Rafael Soares Ribeiro](https://github.com/up201806330) (<up201806330@fe.up.pt>)

## Media

| The original map, as rendered by [OpenStreetMap](https://www.openstreetmap.org/#map=11/41.1373/-8.6524) | As rendered by our program |
|--------------------------------------|--------------------------------------|
| <img src="https://i.imgur.com/UtWtfIR.png" width="500"> | <img src="https://i.imgur.com/wE0zyNw.png" width="670"> |


| `view` - Types of roads              | `speed` - Maximum allowed speed      |
|--------------------------------------|--------------------------------------|
| ![](https://i.imgur.com/Y8ZJyr3.png) | ![](https://i.imgur.com/Njimj9n.png) |

| `path` - Shortest path | `path -v` - Nodes visited by each shortest path algorithm |
|--------------------------------------|--------------------------------------|
| ![](https://i.imgur.com/r3x6KfR.png) | ![](https://i.imgur.com/NIdLnt4.png) |

| `reduce` - Close-up view             | `ride` - Check ride path             |
|--------------------------------------|--------------------------------------|
| ![](https://i.imgur.com/BRxpvq4.png) | ![](https://i.imgur.com/yEcn4Gi.png) |

<table>
    <tr>
        <th>
            <code>scc</code> - Train station strongly connected component
        </th>
        <th>
            Closeup, near Freixo Bridge
        </th>
    </tr>
    <tr>
        <td rowspan=3>
            <img src="https://i.imgur.com/s8YZwUP.png" width="600">
        </td>
        <td>
            <img src="https://i.imgur.com/YwCUPvM.png" width="500">
        </td>
    </tr>
    <tr>
        <th>
            Closeup, near A41 and A32 (Sandim, V. N. Gaia)
        </th>
    </tr>
    <tr>
        <td>
            <img src="https://i.imgur.com/faPYR6B.png" width="500">
        </td>
    </tr>
</table>

## Installing

If you are cloning from GitHub, you should pull all submodules with

```sh
git submodule update --init --recursive # If for the first time
```

### Make commands

```sh
make            # Compile all dependencies and libraries
make clean      # Cleanup files (except submodules and map/)
make cleanall   # Cleanup all files
make test       # Run unit tests
```

`make` automatically downloads the sample map file `map.xml` we used to develop this project, using `wget`. You must install `wget` to properly get the file, or otherwise download `map.zip` from [this link](https://drive.google.com/uc?id=1cEqe8l_cDt1A1aqe7wAWVAMhYqSejv9L), unzip it and copy its content to `map/original`.

## Usage

### Interesting locations

You can use some of these locations to explore most functionalities of this program:

| Location                      | Municipality      | Node number   |
|-------------------------------|-------------------|---------------|
| Monte Crasto                  | Gondomar          | 2454698517    |
| Casa Branca de Gramido        | Gondomar          | 1551005098    |
| Maia city hall                | Maia              | 5272120014    |
| Porto Airport                 | Maia              | 4102094652    |
| SONAE                         | Maia              | 5702537845    |
| Zoo Maia                      | Maia              | 4551001973    |
| EXPONOR                       | Matosinhos        | 1436599811    |
| Fábrica Unicer                | Matosinhos        | 7186948192    |
| NorteShopping                 | Matosinhos        | 4606348154    |
| Port of Leixões               | Matosinhos        | 4612166056    |
| Fábrica Nortada               | Porto             | 286968787     |
| FCUP                          | Porto             | 128672575     |
| FEUP                          | Porto             | 4523960191    |
| Palácio de Cristal            | Porto             | 3391598673    |
| São João Baptista Fortress    | Porto             | 4567051363    |
| Serra de Santa Justa          | Valongo           | 6426059706    |
| Afurada marina                | Vila Nova de Gaia | 1143316550    |
| Monastery of Serra do Pilar   | Vila Nova de Gaia | 3398946056    |
| Sandeman                      | Vila Nova de Gaia | 1143316550    |
| Senhor da Pedra beach         | Vila Nova de Gaia | 4764305642    |
| Zoo Santo Inácio              | Vila Nova de Gaia | 1324797708    |

### Graphical uses

For all graphical uses, `FLAGS` flags which roads to draw (add them to combine):

| Type of road  | Description   | Flag  |
|---------------|---------------|-------|
| Motorway      | Red           |     1 |
| Trunk         | Pink          |     2 |
| Primary       | Orange        |     4 |
| Secondary     | Yellow        |     8 |
| Tertiary      | Gray          |    16 |
| Road          | Gray          |    32 |
| Residential   | Gray          |    64 |
| Slow          | Gray, dashed  |   128 |

#### View

```
./main view FRACTION FLAGS

FRACTION    Fraction of nodes to draw (improves display performance).
FLAGS       Flag which roads to draw (add them to combine).
```

##### Examples

- To see all types of roads with a fraction of 5, run `./main view 5 255`
- To see all main roads with a fraction of 3, run `./main view 3 15`

#### Speed

```
./main speed FRACTION FLAGS

FRACTION    Fraction of nodes to draw (improves display performance).
FLAGS       Flag which roads to draw (add them to combine).
```

Roads are coloured according to the following table:
| Speed [km/h] (up to)  | Colour  |
|-----------------------|---------|
|                   120 | Red     |
|                   100 | Orange  |
|                    80 | Yellow  |
|                    60 | Green   |
|                    50 | Black   |
|                    40 | Gray    |

#### Strongly connected components

```
./main scc FRACTION FLAGS

FRACTION    Fraction of nodes to draw (improves display performance).
FLAGS       Flag which roads to draw (add them to combine).
```

Roads are coloured red if they connect two nodes in the train station's SCC, or gray otherwise.

#### Shortest path

```
./main scc FRACTION FLAGS SOUR DEST [-v]
./main scc FRACTION FLAGS SOUR_LAT SOUR_LON DEST_LAT DEST_LON [-v]

FRACTION    Fraction of nodes to draw (improves display performance).
FLAGS       Flag which roads to draw (add them to combine).
SOUR        Source node (beginning) of the path we are looking for.
SOUR_LAT    Latitude of the source coordinate.
SOUR_LON    Longitude of the source coordinate.
DEST        Destination (end) of the path we are looking for.
DEST_LAT    Latitude of the destination coordinate.
DEST_LON    Longitude of the destination coordinate.
-v          Colour visited nodes according to the algorithms that explored them.
```

You can use either `./main scc FRACTION FLAGS SOUR DEST [-v]` or `./main scc FRACTION FLAGS SOUR_LAT SOUR_LON DEST_LAT DEST_LON [-v]`, where the second option is similar to the first, with only the extra step of finding, for the source and destination coordinates, the closest nodes of the graph that are connected to the train station.

Roads are coloured according to the following table:

| Algorithm                            | Path colour | Visited nodes colour |
|--------------------------------------|-------------|----------------------|
| Dijkstra's algorithm with early stop | Black       | Pink                 |
| A* algorithm, 90km/h                 | Black       | Red                  |
| A* algorithm, 60km/h                 | Magenta     | Magenta              |
| A* algorithm, 30km/h                 | Blue        | Blue                 |
| A* algorithm, 10km/h                 | Cyan        | Cyan                 |

##### Examples

- To get paths between FEUP and FCUP, you can run either of
```sh
./main path 1 255 4523960191 128672575
./main path 1 255 41.1777 -8.598 41.1522 -8.6361
```

#### Reduced

`./main reduced` allows to see the reduced version of the connected graph. This reduced graph was an early effort with the objective of rapidly finding the distance between any two nodes, by reducing the original graph by removing middle nodes in one-way and two-way roads.

#### Rides

```
./main ride FRACTION FLAGS RIDES NUM_RIDES

FRACTION    Fraction of nodes to draw (improves display performance).
FLAGS       Flag which roads to draw (add them to combine).
RIDES       Rides file path (output).
NUM_RIDES   Number of ride to be drawn.
```

Draws ride `NUM_RIDES` from file `RIDES`.

##### Examples

```sh
./main ride 1 255 resources/it1_03.rides 1
```

### Iterations

```
./main (iteration1 | iteration2) CLIENTS VANS RIDES

CLIENTS     Clients file path (input).
VANS        Vans file path (input).
RIDES       Rides file path (output).
```

#### Examples

- To get all rides serving clients in `resources/it1_01.clients`, using vans `resources/it1_01.vans` and outputting those rides to `resources/it1_01.rides`, run
```sh
./main iteration1 resources/it1_01.vans resources/it1_01.clients resources/it1_01.rides
```

Other examples:
```sh
./main iteration1 resources/it1_01.vans resources/it1_02.clients resources/it1_02.rides #Takes around 5 seconds
./main iteration1 resources/it1_01.vans resources/it1_03.clients resources/it1_03.rides #Takes around 8 seconds
./main iteration2 resources/it2_01.vans resources/it1_03.clients resources/it2_01.rides #Takes around 8 seconds
./main iteration2 resources/it2_01.vans resources/it2_01.clients resources/it2_02.rides #Takes around 20 seconds
./main iteration2 resources/it2_01.vans resources/it2_02.clients resources/it2_03.rides #Takes around 35 seconds
```

## Reports

Reports are compiled by Github Actions, to see them go to [`Actions`](https://github.com/dmfrodrigues/feup-cal-proj/actions) > `Workflows` > [`Compile reports`](https://github.com/dmfrodrigues/feup-cal-proj/actions?query=workflow%3A%22Compile+reports%22), go to the most recent action and check `This run > Artifacts`.

You can also check the releases.

## License

© 2020 Diogo Rodrigues, João António Sousa, Rafael Ribeiro

All files are licensed under [GNU General Public License v3](LICENSE), to the exception of:
- submodules, which are subject to specific licenses
- map data, which was extracted from OpenStreetMap under the Open Database License; refer to the report for further details
