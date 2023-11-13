import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { LoginPageComponent } from './login-page/login-page.component';
import { HomePageComponent } from './home-page/home-page.component';

const routes: Routes = [
  {
    path: '',
    component: LoginPageComponent,
    // resolve: {
    //   data: CategoriesResolver
    // }
  },
  {
    path: 'home',
    component: HomePageComponent,
    // resolve: {
    //   data: CategoriesResolver
    // }
  },
];

@NgModule({
  imports: [RouterModule.forRoot(routes,
    { useHash: false })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
