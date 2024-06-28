import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int VertexCnt,EdgeCnt,StartVertex;

	static class Node implements Comparable<Node>{
		int idx, weight;

		public Node(int idx, int weight) {
			super();
			this.idx = idx;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.weight, o.weight);
		}

		@Override
		public String toString() {
			return "Node [idx=" + idx + ", weight=" + weight + "]\n";
		}
		
	}

	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		VertexCnt = Integer.parseInt(st.nextToken()); //정점의 개수
		EdgeCnt = Integer.parseInt(st.nextToken());   //간선의 개수
		StartVertex = Integer.parseInt(br.readLine());//시작 정점
		
		List<Node>[] adjList = new List[VertexCnt+1]; //인접리스트 (1번 정점부터 시작이기 때문에 +1)
		
		
		int[] distance = new int[VertexCnt+1]; //최단거리(가중치) 배열
		
		
		for(int i=1; i<= VertexCnt; i++) {   //1부터 시작하는 정점 번호
			adjList[i] = new ArrayList<>();  //각 정점번호마다 인접한 정점의 정보를 담을 리스트 생성
			distance[i] = Integer.MAX_VALUE; //기본 INF 설정 (아직 정점을 방문하지 않아 최단거리가 정해지지 않음 설정)
		}

		for(int i=0; i<EdgeCnt; i++) {
			//간선의 시작하는 정점과 도달하는 정점의 정보 그리고 가중치 정보를 ==> 각 리스트에 저장
			st = new StringTokenizer(br.readLine());
			int sVertex = Integer.parseInt(st.nextToken());
			int tVertex = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			adjList[sVertex].add(new Node(tVertex,weight));
		}

		distance[StartVertex] = 0; //시작정점은 0으로 표시
		
		PriorityQueue<Node> pq = new PriorityQueue<>(); //최소거리를 구하기 위해 사용
		
		pq.offer(new Node(StartVertex,0)); //시작정점 저장후 스타트!!
		
		boolean[] visited = new boolean[VertexCnt+1]; //정점 방문 처리
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();    //최소거리(가중치)를 빼옴
			visited[cur.idx] = true; //정점 방문처리
			
			for(Node node : adjList[cur.idx]) {
				if(!visited[node.idx] &&  //아직 방문하지 않은 정점이고
				    distance[node.idx] > distance[cur.idx]+node.weight) { //짧은 거리(가중치)가 존재한다면
					
					distance[node.idx] = distance[cur.idx]+node.weight;//짧은 거리(가중치) 갱신
					node.weight = distance[node.idx];//정점 거리(가중치) 갱신
					pq.offer(node);//정점정보 저장                  
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i=1; i<=VertexCnt; i++) {
			if(distance[i] == Integer.MAX_VALUE) sb.append("INF\n");
			else sb.append(distance[i]).append("\n");
		}
		System.out.println(sb);
	}

}