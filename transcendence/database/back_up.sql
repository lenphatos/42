PGDMP              
    	        z            db #   12.9 (Ubuntu 12.9-0ubuntu0.20.04.1) #   12.9 (Ubuntu 12.9-0ubuntu0.20.04.1)     ?           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            ?           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            ?           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            ?           1262    16385    db    DATABASE     t   CREATE DATABASE db WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';
    DROP DATABASE db;
                ft_root    false            ?            1259    16405 	   all_users    VIEW     S   CREATE VIEW public.all_users AS
 SELECT "user"."user"
   FROM USER "user"("user");
    DROP VIEW public.all_users;
       public          ft_root    false            ?            1259    16386    typeorm_metadata    TABLE     ?   CREATE TABLE public.typeorm_metadata (
    type character varying NOT NULL,
    database character varying,
    schema character varying,
    "table" character varying,
    name character varying,
    value text
);
 $   DROP TABLE public.typeorm_metadata;
       public         heap    ft_root    false            ?            1259    16394    user    TABLE     ?   CREATE TABLE public."user" (
    id integer NOT NULL,
    login character varying(64) NOT NULL,
    name character varying(64) NOT NULL,
    "isOnline" boolean DEFAULT false NOT NULL
);
    DROP TABLE public."user";
       public         heap    ft_root    false            ?            1259    16392    user_id_seq    SEQUENCE     ?   CREATE SEQUENCE public.user_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 "   DROP SEQUENCE public.user_id_seq;
       public          ft_root    false    204            ?           0    0    user_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.user_id_seq OWNED BY public."user".id;
          public          ft_root    false    203            !           2604    16397    user id    DEFAULT     d   ALTER TABLE ONLY public."user" ALTER COLUMN id SET DEFAULT nextval('public.user_id_seq'::regclass);
 8   ALTER TABLE public."user" ALTER COLUMN id DROP DEFAULT;
       public          ft_root    false    203    204    204            ?          0    16386    typeorm_metadata 
   TABLE DATA                 public          ft_root    false    202   G       ?          0    16394    user 
   TABLE DATA                 public          ft_root    false    204   a       ?           0    0    user_id_seq    SEQUENCE SET     9   SELECT pg_catalog.setval('public.user_id_seq', 9, true);
          public          ft_root    false    203            ?   
   x???          ?   ?   x???v
Q???W((M??L?S*-N-RR??L?Q??O???Q?K?M?QP?,?????KU?Ts?	uV?0?QPO????/-R2??K??K???Ĝ?TMk.O
ͷ ????????L,?????`5?? ??V1     