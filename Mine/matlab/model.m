%1. 计算可衡量影响
%%1.1 经济因素：
D = GGDP (:, 1) - GGDP (:, 2);
sort_D = ( max (D (:, 1)) - D (:, 1)) ./ ( max (D (:, 1)) - min (D(:,1)));
Motivition=1./(1+exp(3*(1-2*sort_D(:,1))));
gdpr=GGDP(: ,1); ggdpr=GGDP(:, 2);
pd=find(ggdpr(: ,1) )-find(gdpr(:, 1 ));
if max(pd)-min(pd) ==0 
    pd=ones(size(GGDP, 1) , 1)*0.02;
else 
    pd=0.98 * ( (pd(:, 1)-min(pd(:, 1)) ) ./ ( max( pd(: ,1) )-min( pd(:, 1) ) ) ) + 0.02;
end
%%1.2 政治因素
sort_FS=(max(FS(:,1))-FS(:,1) ) ./ (max(FS(:,1))-min(FS(:,1) ) );
sort_gdp=(gdp(:, 1)-min(gdp(:, 1)) ) ./ ( max( gdp(: ,1) )-min( gdp(:, 1) ) ); 
gdpr=(gdpr(:, 1)-min(gdpr(:, 1)) ) ./ ( max( gdpr(: ,1) )-min( gdpr(:, 1) ) );
alpha=0.65; beata=0.5;
YiYuan_2=alpha*pd+(1-alpha)*sort_FS;
YiYuan_1=beata*sort_gdp+(1-beata)*gdpr; 
Inclination=sqrt(YiYuan_1 .* YiYuan_2);
%%1.3 整合，使用熵权法计算权值
p=Motivition ./ sum( Motivition ) ;
p=p.*log(p);
e= -(1 ./size(GGDP, 1)) * p;
e=1-e ;
w_1=e./sum(e) ;
p=Inclination ./ sum( Inclination ) ;
p=p.*log(p);
e= -(1 ./size(GGDP, 1)) * p;
e=1-e ;
w_2=e./sum(e) ;
Impact_ex=( Motivition(:,1) .^ w_1(:,1)) .* (Inclination(:,1) .^ w_2(:,1) );
%2 将影响映射到气候上
%%2.1 层次分析法计算权重
w_3=nthroot(prod(JuZhen,2),size(JuZhen,1));
w_3=w_3./sum(w_3);
lamda_max=max(eig(JuZhen));
CI=(lamda_max-size(JuZhen,1)) ./ (size(JuZhen,1)-1);
RI=0.58;
CR=CI/RI 
sort_Climate=Climate;
sort_Climate(:,1)=(max(Climate(:,1))-Climate(:,1))/(max(Climate(:,1))-min(Climate(:,1)));
sort_Climate(:,2:3)=(Climate(:, 2:3)-min(Climate(:, 2:3)) ) ./ ( max( Climate(: ,2:3) )-min( Climate(:, 2:3) ) ); 
Envirnoment_sp=sort_Climate*w_3;

%%2.2 整合数据，预测全球气候缓解积极影响。
syms n m
equ_1=[100==40*log(n-min(Envirnoment_sp))+m, 0.1==40*log(n-max(Envirnoment_sp))+m];
roots_1=solve(equ_1,[m,n]);
En__=log(roots_1.n-Envirnoment_sp)+roots_1.m;
deata_En=(En__) .^ Impact_ex - Envirnoment_sp;
%%2.3 计算阻力和优越性，以及效率
poriority=log(deata_En)./log(1./Envirnoment_sp);
poriority=double(poriority);
syms a b;
equ=[1==-log(min(Impact_ex)+a)+b , 0.02==-log(max(Impact_ex)+a)+b];
roots=solve(equ,[a,b]);
resistance=-log(Impact_ex+roots.a)+roots.b;
Effect=log(poriority./resistance);
Effect_a=mean(Effect);
Effect_standerd=log( mean(poriority)/mean(resistance) );
dE=Effect_a-Effect_standerd;
%3. 展示最终结果
dE=double(dE)