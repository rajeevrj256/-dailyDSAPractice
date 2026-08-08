class Twitter {
    Map<Integer,Set<Integer>>following;
    HashMap<Integer,List<List<Integer>>>news;
    int posttime=0;
    public Twitter() {
        following=new HashMap<>();
        news=new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
       news.computeIfAbsent(userId, k -> new ArrayList<>())
                 .add(Arrays.asList(posttime, tweetId));
        posttime++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> friends = following.getOrDefault(userId, new HashSet<>());
        friends.add(userId);
        PriorityQueue<List<Integer>> userPost = new PriorityQueue<>((a,b)-> Integer.compare(b.get(0),a.get(0)));

        for(int friend:friends){
            List<List<Integer>>posts=news.getOrDefault(friend,new ArrayList<>());
            for(List<Integer> post:posts){
            userPost.offer(post);
            }
        }
        List<Integer>ans= new ArrayList<>();

        while(!userPost.isEmpty() && ans.size()<10){
            ans.add(userPost.poll().get(1));
            
        }

        return ans;
        
    }
    
    public void follow(int followerId, int followeeId) {
        following.computeIfAbsent(followerId,k->new HashSet<>()).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
       following.getOrDefault(followerId,new HashSet<>()).remove(followeeId);
    }
}
